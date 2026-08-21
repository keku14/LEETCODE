class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        vector<int> dx= {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};

        for(int k = 0;k<4;k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1' && vis[ni][nj] == 0){
                dfs(ni,nj,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};