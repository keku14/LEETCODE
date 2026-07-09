class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> prev(c, vector<int>(c, 0));

        // Base case: last row
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                if (j1 == j2) prev[j1][j2] = grid[r - 1][j1];
                else prev[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }

        // Fill from bottom to top
        for (int i = r - 2; i >= 0; i--) {
            vector<vector<int>> temp(c,vector<int>(c,0));
            for (int j1 = 0; j1 < c; j1++) {
                for (int j2 = 0; j2 < c; j2++) {

                    int maxi = INT_MIN;

                    for (int k = -1; k <= 1; k++) {
                        for (int l = -1; l <= 1; l++) {

                            int nj1 = j1 + k;
                            int nj2 = j2 + l;

                            if (nj1 >= 0 && nj1 < c && nj2 >= 0 && nj2 < c) {
                                int curr = 0;
                                if (j1 == j2) curr += grid[i][j1];
                                else curr += grid[i][j1] + grid[i][j2];
                                curr += prev[nj1][nj2];
                                maxi = max(maxi, curr);
                            }
                        }
                    }
                    temp[j1][j2] = maxi;
                }
            }
            prev = temp;
        }

        return prev[0][c - 1];
    }
};


// Tabulation
// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int r = grid.size();
//         int c = grid[0].size();

//         vector<vector<vector<int>>> dp(
//             r, vector<vector<int>>(c, vector<int>(c, 0)));

//         // Base case: last row
//         for (int j1 = 0; j1 < c; j1++) {
//             for (int j2 = 0; j2 < c; j2++) {
//                 if (j1 == j2) dp[r - 1][j1][j2] = grid[r - 1][j1];
//                 else dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
//             }
//         }

//         // Fill from bottom to top
//         for (int i = r - 2; i >= 0; i--) {
//             for (int j1 = 0; j1 < c; j1++) {
//                 for (int j2 = 0; j2 < c; j2++) {

//                     int maxi = INT_MIN;

//                     for (int k = -1; k <= 1; k++) {
//                         for (int l = -1; l <= 1; l++) {

//                             int nj1 = j1 + k;
//                             int nj2 = j2 + l;

//                             if (nj1 >= 0 && nj1 < c && nj2 >= 0 && nj2 < c) {
//                                 int curr = 0;
//                                 if (j1 == j2) curr += grid[i][j1];
//                                 else curr += grid[i][j1] + grid[i][j2];
//                                 curr += dp[i + 1][nj1][nj2];
//                                 maxi = max(maxi, curr);
//                             }
//                         }
//                     }
//                     dp[i][j1][j2] = maxi;
//                 }
//             }
//         }

//         return dp[0][0][c - 1];
//     }
// };

// Memoization
//  class Solution {
//  public:
//      int fn(int row,int j1,int j2,int c,vector<vector<int>>& grid,
//      vector<vector<vector<int>>> dp){
//          if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c){
//              return 0;
//          }
//          if(row == grid.size()-1){
//              if(j1 == j2) return grid[row][j1];
//              else return grid[row][j1] + grid[row][j2];
//          }
//          if(dp[row][j1][j2] != -1 ) return dp[row][j1][j2];
//          int maxi = 0;
//          for(int k = -1;k<=1;k++){
//              for(int l = -1;l<=1;l++){
//                  int curr = 0;
//                  if(j1 == j2) curr += grid[row][j1];
//                  else curr += grid[row][j1] + grid[row][j2];

//                 curr += fn(row+1,j1+k,j2+l,c,grid,dp);
//                 maxi = max(maxi,curr);
//             }
//         }
//         return dp[row][j1][j2] = maxi;
//     }
//     int cherryPickup(vector<vector<int>>& grid) {
//         int r = grid.size();
//         int c = grid[0].size();

//         vector<vector<vector<int>>>
//         dp(r,vector<vector<int>>(c,vector<int>(c,-1))); return
//         fn(0,0,c-1,c,grid,dp);
//     }
// };