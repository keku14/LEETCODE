class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mpp;

        for (string s : cpdomains) {

            int space = s.find(' ');
            int cnt = stoi(s.substr(0, space));
            string domain = s.substr(space + 1);

            mpp[domain] += cnt;

            for (int i = 0; i < domain.size(); i++) {
                if (domain[i] == '.') {
                    mpp[domain.substr(i + 1)] += cnt;
                }
            }
        }

        vector<string> ans;

        for (auto &it : mpp) {
            ans.push_back(to_string(it.second) + " " + it.first);
        }

        return ans;
    }
};