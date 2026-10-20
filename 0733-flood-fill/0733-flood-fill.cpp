class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int inicol = image[sr][sc];
        if(inicol == color) return image;

  
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[sr][sc] = 1;
       
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            image[x][y] = color;
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<n && ny >= 0&& ny<m && image[nx][ny] == inicol && vis[nx][ny] == 0){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return image;
    }
};