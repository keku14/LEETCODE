// Space opt
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<int> prev(n,0);
        for(int i = 0;i<n;i++){
            prev[i] = matrix[0][i];
        }
        for (int j = 1; j < n; j++){
            vector<int> temp(n,0);
            for(int i = 0;i<n;i++){
                int up = prev[i];
                int left = 1e9;
                int right = 1e9;

                if(i-1 >= 0) left = prev[i-1];
                if(i+1 < n) right = prev[i+1];

                temp[i] = matrix[j][i] + min({up,left,right});
            }
            prev = temp;
        }
        for(int j = 0;j<n;j++){
            ans = min(ans,prev[j]);
        }
        return ans;
    }
};



// Tabulation
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int ans = INT_MAX;
//         vector<vector<int>> dp(n,vector<int>(n,0));
//         for(int i = 0;i<n;i++){
//             dp[0][i] = matrix[0][i];
//         }
//         for (int j = 1; j < n; j++){
//             for(int i = 0;i<n;i++){
//                 int up = dp[j-1][i];
//                 int left = 1e9;
//                 int right = 1e9;

//                 if(i-1 >= 0) left = dp[j-1][i-1];
//                 if(i+1 < n) right = dp[j-1][i+1];

//                 dp[j][i] = matrix[j][i] + min({up,left,right});
//             }
//         }
//         for(int j = 0;j<n;j++){
//             ans = min(ans,dp[n-1][j]);
//         }
//         return ans;
//     }
// };


// Memoization
// class Solution {
// public:
//     int fn(int row, int col, vector<vector<int>>& matrix,vector<vector<int>>& dp) {
//         int n = matrix.size();
//         if (col < 0 || col >= n) return 1e9;

//         if (row == n - 1) return matrix[row][col];
        
//         if(dp[row][col] != -101){
//             return dp[row][col];
//         }

//         int down = fn(row + 1, col, matrix, dp);
//         int left = fn(row + 1, col - 1, matrix, dp);
//         int right = fn(row + 1, col + 1, matrix, dp);

//         return dp[row][col] = matrix[row][col] + min({down, left, right});
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n,vector<int>(n,-101));
//         for (int j = 0; j < n; j++)
//             dp[0][j] = fn(0, j, matrix,dp);

//         int ans = INT_MAX;
//         for (int j = 0; j < n; j++)
//             ans = min(ans, dp[0][j]);

//         return ans;
//     }
// };



// Recursion
// class Solution {
// public:
//     int fn(int row, int col, vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         if (col < 0 || col >= n) return 1e9;
//         if (row == n - 1) return matrix[row][col];

//         int down = fn(row + 1, col, matrix);
//         int left = fn(row + 1, col - 1, matrix);
//         int right = fn(row + 1, col + 1, matrix);

//         return matrix[row][col] + min({down, left, right});
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int ans = INT_MAX;
//         for (int j = 0; j < n; j++)
//             ans = min(ans, fn(0, j, matrix));

//         return ans;
//     }
// };