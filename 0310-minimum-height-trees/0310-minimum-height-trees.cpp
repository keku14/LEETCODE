class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> inde(n, 0);

        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

            inde[it[0]]++;
            inde[it[1]]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(inde[i] == 1) q.push(i);
        }

        vector<int> level;

        while(!q.empty()){
            int size = q.size();
            level.clear();

            for(int i = 0; i < size; i++){
                int x = q.front();
                q.pop();

                level.push_back(x);
                for(auto it : adj[x]){
                    inde[it]--;
                    if(inde[it] == 1) q.push(it);
                }
            }
        }

        return level;
    }
};