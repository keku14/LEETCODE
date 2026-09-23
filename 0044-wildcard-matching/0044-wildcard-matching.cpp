class Solution {
public:
    bool fn(string& s,string& p,int i,int j,vector<vector<int>>& dp){
        if(i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;

        if(i < 0 && j >= 0){
            for(int k = 0;k<=j;k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        if(p[j] == '?' || s[i] == p[j]){
            ans = fn(s,p,i-1,j-1,dp);
        }

        if(p[j] == '*'){
            ans = fn(s,p,i,j-1,dp) || fn(s,p,i-1,j,dp);
        }

        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fn(s,p,n-1,m-1,dp);
    }
};