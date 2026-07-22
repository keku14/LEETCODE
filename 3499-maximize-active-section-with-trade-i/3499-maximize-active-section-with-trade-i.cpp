class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int cnt1 = 0;
        for(auto it : s){
            if(it == '1') cnt1++;
        }
        vector<int> v;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '0'){
                cnt++;
            }else{
                if(cnt != 0){
                    v.push_back(cnt);
                    cnt = 0;
                }else{
                    continue;
                }
            }
        }
        if(cnt != 0){
            v.push_back(cnt);
            cnt = 0;
        }
        if(v.size() <= 1) return cnt1;

        int x = INT_MIN;
        for(int i = 0;i<v.size()-1;i++){
            x = max(x,v[i]+v[i+1]);
        }
        return cnt1+x;
    }
};