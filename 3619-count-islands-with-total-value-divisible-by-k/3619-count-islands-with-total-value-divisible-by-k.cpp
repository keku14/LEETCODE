class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count  = 0;
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] != 0 && !visited[i][j]){
                    long long sum = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        sum += grid[x][y];
                        for(auto& d:directions){
                            int nx = x+d.first;
                            int ny = y+d.second;

                            if(nx >= 0 && nx<n && ny>= 0 && ny<m && grid[nx][ny] >0 && !visited[nx][ny]){
                                visited[nx][ny] = true;
                                q.push({nx,ny});
                            }
                        }
                    }
                    if(sum % k == 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};