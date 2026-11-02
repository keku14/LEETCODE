//space opt
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        if (mat[0][0] == 1)
            return 0;
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n,0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0){
                    temp[j] = 1;
                    continue;
                }
                if(mat[i][j] == 1){
                    temp[j] = 0;
                    continue;
                }
                int up = 0;
                if(i > 0) up = prev[j];
                int left = 0;
                if(j > 0) left = temp[j - 1];

                temp[j] = up + left;
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};


// Tabulation
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();
//         if (mat[0][0] == 1)
//             return 0;
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         dp[0][0] = 1;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == 0 && j == 0) continue;
//                 if (mat[i][j] == 1) {
//                     dp[i][j] = 0;
//                     continue;
//                 }

//                 int up = 0;
//                 if(i>0) up = dp[i - 1][j];
//                 int left = 0;
//                 if(j > 0) left = dp[i][j - 1];

//                 dp[i][j] = up + left;
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// Memoization
// class Solution {
// public:
//     int fn(vector<vector<int>>& mat,vector<vector<int>>& dp,int i,int j){
//         if(i < 0 || j < 0) return 0;
//         if(i == 0 && j == 0) return 1;

//         if(mat[i][j] == 1) return 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         int up = fn(mat,dp,i-1,j);
//         int left = fn(mat,dp,i,j-1);

//         return dp[i][j] = up + left;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();
//         if(mat[0][0] == 1) return 0;
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return fn(mat,dp,m-1,n-1);
//     }
// };

// reccursion
//  class Solution {
//  public:
//      vector<int> dx = {0,1};
//      vector<int> dy = {1,0};
//      void fn(int m,int n,vector<vector<int>>& mat,int& cnt,int i,int j){
//          if(i == m-1 && j == n-1){
//              cnt++;
//              return;
//          }

//         for(int k = 0;k<2;k++){
//             int ni = i + dx[k];
//             int nj = j + dy[k];

//             if(ni >= 0 && ni < m && nj >= 0 && nj < n && mat[ni][nj] != 1){
//                 fn(m,n,mat,cnt,ni,nj);
//             }
//         }
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& mat) {
//         int cnt = 0;
//         int m = mat.size();
//         int n = mat[0].size();
//         if(mat[0][0] == 1) return 0;
//         fn(m,n,mat,cnt,0,0);
//         return cnt;
//     }
// };