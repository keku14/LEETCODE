class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0;
        int cnt = 0;
        for(auto it : s){
            if(it == c){
                cnt++;
                ans += cnt;
            }
        }
        return ans;
    }
};