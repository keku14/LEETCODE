class Solution {
public:
    int fn(int row, int col, vector<vector<int>>& matrix,vector<vector<int>>& dp) {

        int n = matrix.size();

        if (col < 0 || col >= n)
            return 1e9;

        if (row == n - 1)
            return matrix[row][col];
        
        if(dp[row][col] != -101){
            return dp[row][col];
        }

        int down = fn(row + 1, col, matrix, dp);
        int left = fn(row + 1, col - 1, matrix, dp);
        int right = fn(row + 1, col + 1, matrix, dp);

        return dp[row][col] = matrix[row][col] + min({down, left, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-101));
        for (int j = 0; j < n; j++)
            dp[0][j] = fn(0, j, matrix,dp);

        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
            ans = min(ans, dp[0][j]);

        return ans;
    }
};