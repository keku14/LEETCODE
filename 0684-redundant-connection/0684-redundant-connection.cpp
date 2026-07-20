class Solution {
private:
    bool check(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                queue<pair<int, int>> q;
                q.push({i, -1});
                vis[i] = 1;

                while (!q.empty()) {
                    auto [node, parent] = q.front();
                    q.pop();

                    for (auto it : adj[node]) {
                        if (!vis[it]) {
                            vis[it] = 1;
                            q.push({it, node});
                        } else if (it != parent) {
                            return true; // cycle found
                        }
                    }
                }
            }
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        for(int i=n-1; i>=0; i--){
            vector<vector<int>> temp;
            for(int j=n-1; j>=0; j--){
                if(j!=i) temp.push_back(edges[j]);
            }
            if(check(temp) == false){
                //no cycle
                return edges[i];
            }
        }
        return {};
    }
};