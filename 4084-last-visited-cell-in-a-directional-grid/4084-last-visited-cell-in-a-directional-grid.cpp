class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            int nr = -1;
            int nc = -1;
            if(grid[r][c] == 'L'){
                nc = c - 1;
                nr = r;
            }
            else if(grid[r][c] == 'R'){
                nc = c + 1;
                nr = r;
            } 
            else if(grid[r][c] == 'U'){
                nc = c;
                nr = r - 1;
            } 
            else{
                nc = c;
                nr = r + 1;
            } 

            if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] == 1){
                return {r,c};
            }else{
                q.push({nr,nc});
                vis[nr][nc] = 1;
            }
        }
        return {0,0};
    }
};