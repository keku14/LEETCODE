class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>> pq;
        
        int n = heightMap.size();
        int m = heightMap[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][m-1],{i,m-1}});
            vis[i][0] = vis[i][m-1] = 1;
        }
        for(int j = 0;j<m;j++){
            pq.push({heightMap[0][j],{0,j}});
            pq.push({heightMap[n-1][j],{n-1,j}});
            vis[0][j] = vis[n-1][j] = 1;
        }
        int ans = 0;
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        while(!pq.empty()){
            int h = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(int k = 0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];

                if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]){
                    ans += max(0,h - heightMap[ni][nj]);
                    vis[ni][nj] = 1;
                    pq.push({max(h, heightMap[ni][nj]),{ni,nj}});
                }
            }
        }
        return ans;
    }
};