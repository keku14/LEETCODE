class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i = 0;i<s.length();i++){
            ans += (i+1)*abs(s[i]-'z'-1);
        }
        return ans;
    }
};