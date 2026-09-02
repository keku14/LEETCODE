class Solution {
public:
    int fn(int i,int j,string& str1,string& str2,vector<vector<int>>& dp){
        if(j < 0) return i+1;
        if(i < 0) return j+1;

        if(dp[i][j] != -1) return dp[i][j];

        if(str1[i] == str2[j]) return fn(i-1,j-1,str1,str2,dp); 

        int a = 1 + fn(i,j-1,str1,str2,dp);  //insert
        int b = 1 + fn(i-1,j,str1,str2,dp);     //delete
        int c = 1 + fn(i-1,j-1,str1,str2,dp);      // replace

        return dp[i][j] = min({a,b,c});
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fn(n-1,m-1,word1,word2,dp);
    }
};