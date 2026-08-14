class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mpp;
        int l = 0;int r = 0;
        int n = s.length();
        int ans = 1;
        while(r < n){
            if(!mpp.count(s[r])){
                mpp[s[r]]++;
            }else{
                int x = mpp[s[r]];
                if(x+1 > 2){
                    while(l < r && s[l] != s[r]){
                        mpp[s[l]]--;
                        l++;
                    }
                    mpp[s[l]]--;
                    l++;
                }
                mpp[s[r]]++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};