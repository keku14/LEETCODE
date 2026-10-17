// Space opt
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<int> prev(n);

//         for(int i = 0;i<m;i++){
//             vector<int> temp(n,0);
//             for(int j = 0;j<n;j++){
//                 if(i == 0 && j == 0) {
//                     temp[j] = 1;
//                     continue;
//                 }
//                 int up = 0,left = 0;

//                 if(i > 0 ) up = prev[j];
//                 if(j > 0 ) left = temp[j-1];

//                 temp[j] = up + left;
//             }
//             prev = temp;
//         }
//         return prev[n-1];
//     }
// };


// Tabulation
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         dp[0][0] = 1;

//         for(int i = 0;i<m;i++){
//             for(int j = 0;j<n;j++){
//                 if(i == 0 && j == 0) continue;
//                 int up = 0,left = 0;

//                 if(i-1 >= 0 ) up = dp[i-1][j];
//                 if(j-1 >= 0 ) left = dp[i][j-1];

//                 dp[i][j] = up + left;
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };


//Memoization
class Solution {
public:
    int x,y;
    int fn(vector<vector<int>>& dp,int i,int j){
        if(i >= x || j >= y) return 0;
        if(i == x-1 && j == y-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];
        
        int down = fn(dp,i+1,j);
        int right = fn(dp,i,j+1);

        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        x = m;
        y = n;
        return fn(dp,0,0);
    }
};


// RECURSION
// class Solution {
// public:
//     vector<int> dx = {0,1};
//     vector<int> dy = {1,0};
//     int x ,y;
//     void fn(int& cnt,int i,int j){
//         if(i == x-1 && j == y-1){
//             cnt++;
//             return;
//         }

//         for(int k = 0;k<2;k++){
//             int ni = i + dx[k];
//             int nj = j + dy[k];

//             if(ni >= 0 && ni < x && nj >= 0 && nj < y){
//                 fn(cnt,ni,nj);
//             }
//         }
//     }
//     int uniquePaths(int m, int n) {
//         int cnt = 0;
//         x = m;
//         y = n;
//         fn(cnt,0,0);
//         return cnt;
//     }
// };