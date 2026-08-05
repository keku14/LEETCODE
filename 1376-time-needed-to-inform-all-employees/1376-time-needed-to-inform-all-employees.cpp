class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++){
            if(manager[i] != -1) adj[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        q.push({headID,informTime[headID]});
        int time = informTime[headID];
        vector<int> vis(n,0);
        vis[headID] = 1;
        while(!q.empty()){
            int id = q.front().first;
            int t = q.front().second;
            time = max(time , t);
            q.pop();
            for(auto it : adj[id]){
                if(!vis[it]){
                    q.push({it,informTime[it]+t});
                    vis[it] = 1;
                }
            }
        }
        return time;
    }
};