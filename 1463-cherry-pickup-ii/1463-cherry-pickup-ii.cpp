class Solution {
public:
    int fn(int row,int j1,int j2,int c,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c){
            return 0;
        }
        if(row == grid.size()-1){
            if(j1 == j2) return grid[row][j1];
            else return grid[row][j1] + grid[row][j2];
        }
        if(dp[row][j1][j2] != -1 ) return dp[row][j1][j2];
        int maxi = 0;
        for(int k = -1;k<=1;k++){
            for(int l = -1;l<=1;l++){
                int curr = 0;
                if(j1 == j2) curr += grid[row][j1];
                else curr += grid[row][j1] + grid[row][j2];

                curr += fn(row+1,j1+k,j2+l,c,grid,dp);
                maxi = max(maxi,curr);
            }
        }
        return dp[row][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return fn(0,0,c-1,c,grid,dp);
    }
};