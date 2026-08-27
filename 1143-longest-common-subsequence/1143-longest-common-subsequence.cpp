class Solution {
public:
    int fn(string& text1,string& text2,int i,int j,vector<vector<int>>& dp){
        if(i <0 || j <0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + fn(text1,text2,i-1,j-1,dp);
        }else{
            ans = 0 + max(fn(text1,text2,i-1,j,dp) , fn(text1,text2,i,j-1,dp));
        }

        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fn(text1,text2,n-1,m-1,dp);
    }
};