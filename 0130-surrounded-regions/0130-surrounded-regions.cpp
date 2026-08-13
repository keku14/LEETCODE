// class Solution {
//   public:
//   void dfs(int row,int col,vector<vector<int>>& visi,vector<vector<char>>& grid,int n,int m){
//       visi[row][col] = 1;
//       vector<int> dx = {-1,0,1,0};
//       vector<int> dy = {0,1,0,-1};
      
//       for(int i = 0;i<4;i++){
//           int nrow = row + dx[i];
//           int ncol = col + dy[i];
          
//           if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol] == 'O' && visi[nrow][ncol] == 0){
//               dfs(nrow,ncol,visi,grid,n,m);
//           }
//       }
//   }
//     void solve(vector<vector<char>>& grid) {
//         // Code here
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> visi(n,vector<int>(m,0));
//         for(int i = 0;i<n;i++){
//             if(grid[i][0] == 'O' && visi[i][0] == 0){
//                 dfs(i,0,visi,grid,n,m);
//             }
//             if(grid[i][m-1] == 'O' && visi[i][m-1] == 0){
//                 dfs(i,m-1,visi,grid,n,m);
//             }
//         }
//         for(int j = 0;j<m;j++){
//             if(grid[0][j] == 'O' && visi[0][j] == 0){
//                 dfs(0,j,visi,grid,n,m);
//             }
//             if(grid[n-1][j] == 'O' && visi[n-1][j] == 0){
//                 dfs(n-1,j,visi,grid,n,m);
//             }
//         }
        
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<m;j++){
//                 if(grid[i][j] == 'O' && visi[i][j] == 0){
//                     grid[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };
class Solution {
  public:
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visi(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        
        for(int i = 0;i<n;i++){
            if(grid[i][0] == 'O'){
                q.push({i,0});
                visi[i][0] = 1;
            }
            if(grid[i][m-1] == 'O'){
                q.push({i,m-1});
                visi[i][m-1] = 1;
            }
        }
        for(int j = 0;j<m;j++){
            if(grid[0][j] == 'O'){
                q.push({0,j});
                visi[0][j] = 1;
            }
            if(grid[n-1][j] == 'O'){
                q.push({n-1,j});
                visi[n-1][j] = 1;
            }
        }
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            visi[row][col] = 1;
            
            for(int i = 0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol] == 'O' && visi[nrow][ncol] == 0){
                    q.push({nrow,ncol});
                    visi[nrow][ncol] = 1;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 'O' && visi[i][j] == 0){
                    grid[i][j] = 'X';  
                }
            }
        }
    }
};



























