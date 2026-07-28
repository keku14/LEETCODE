class Solution {
    bool check(string a, string b){
        vector<char> oa, ea, ob, eb;

        for(int i = 0; i < a.size(); i++){
            if(i % 2 == 0){
                ea.push_back(a[i]);
                eb.push_back(b[i]);
            }else{
                oa.push_back(a[i]);
                ob.push_back(b[i]);
            }
        }

        sort(oa.begin(), oa.end());
        sort(ea.begin(), ea.end());
        sort(ob.begin(), ob.end());
        sort(eb.begin(), eb.end());

        return ea == eb && oa == ob;
    }

public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++){
            if(vis[i]) continue;

            vis[i] = 1;      // mark representative
            ans++;

            for(int j = i + 1; j < n; j++){
                if(!vis[j] && check(words[i], words[j])){
                    vis[j] = 1;
                }
            }
        }

        return ans;
    }
};