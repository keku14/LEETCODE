class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<m;i++){
            for(int j= 0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();
            for(int k = 0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];

                if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1){
                    q.push({{ni,nj},t+1});
                    time = t+1;
                    grid[ni][nj]=2;
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};