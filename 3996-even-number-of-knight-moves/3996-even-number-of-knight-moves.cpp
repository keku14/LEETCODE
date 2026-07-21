class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        if(start == target) return true;
        vector<int> dx={-2,-1,1,2,1,2,-1,-2};
        vector<int> dy={1,2,2,1,-2,-1,-2,-1};
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> vis(8, vector<int>(8,0));
        q.push({0,{start[0],start[1]}});
        vis[start[0]][start[1]] = 1;
        int tx=target[0];
        int ty=target[1];
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int row=it.second.first;
            int col=it.second.second;
            int cnt=it.first;
            if(row==tx && col==ty) return cnt%2==0;
            for(int i=0; i<dx.size(); i++){
                int nr=row+dx[i];
                int nc=col+dy[i];
                if(nr>=0 && nr<=7 && nc>=0 && nc<=7 && !vis[nr][nc]){
                    q.push({cnt+1,{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }
        return false;
    }
};