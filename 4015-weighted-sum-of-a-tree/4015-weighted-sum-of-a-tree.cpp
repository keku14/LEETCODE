class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for(int i = 1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        int height = 0;
        long long ans = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                int node = q.front();
                q.pop();
                for(auto it : adj[node]){
                    q.push(it);
                }
            }
            height++;
        }
        cout << height << endl;
        int d = 1;
        q.push(0);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                int node = q.front();
                q.pop();
                ans += 1LL*nums[node]*(height-d+1);
                cout << node << " " << d << endl;
                for(auto it : adj[node]){
                    q.push(it);
                }
            }
            d++;
        }
        return ans;
    }
};