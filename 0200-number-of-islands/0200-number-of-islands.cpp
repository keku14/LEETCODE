class Solution {
public:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    void fn(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            //vis[r][c] = 1;

            for(int k = 0;k<4;k++){
                int nr = r + dx[k];
                int nc = c + dy[k];
                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == '1' && vis[nr][nc] == 0){
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    fn(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};