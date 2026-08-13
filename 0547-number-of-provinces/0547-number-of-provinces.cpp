class Solution {
public:
    // void fn(vector<vector<int>>& adj,vector<int>& vis,int i){
    //     queue<int> q;
    //     q.push(i);
    //     vis[i] = 1;
    //     while(!q.empty()){
    //         int x = q.front();
    //         q.pop();
    //         for(auto it : adj[x]){
    //             if(!vis[it]){
    //                 q.push(it);
    //                 vis[it] = 1;
    //             }
    //         }
    //     }

    //     return;
    // }
    void fn(vector<vector<int>>& adj,vector<int>& vis,int i){
        vis[i] = 1;
        for(auto it : adj[i]){
            if(!vis[it]) fn(adj,vis,it);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n,0);
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans++;
                fn(adj,vis,i);
            }
        }
        return ans;
    }
};