class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> k = strs;
        int n = k.size();
        for(int i = 0;i<n;i++){
            sort(k[i].begin(),k[i].end());
        }
        for(auto it : k){
            cout << it << endl;
        }
        cout << endl;
        unordered_map<string,vector<int>> mpp;
        for(int i = 0;i<n;i++){
            mpp[k[i]].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto it : mpp){
            vector<int> l = it.second;
            vector<string> temp;
            for(int i = 0;i<l.size();i++){
                temp.push_back(strs[l[i]]);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};