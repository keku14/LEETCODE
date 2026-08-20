class Solution { 
public: 
    vector<bool> checkIfPrerequisite(int numCourses, 
                                     vector<vector<int>>& prerequisites, 
                                     vector<vector<int>>& queries) { 
        
        vector<vector<int>> adj(numCourses); 
        
        for(auto it : prerequisites) { 
            adj[it[0]].push_back(it[1]); 
        } 
        
        int n = queries.size(); 
        vector<bool> ans(n, false); 
        
        for(int i = 0; i < n; i++) { 
            int u = queries[i][0]; 
            int v = queries[i][1]; 
            
            queue<int> q; 
            q.push(u); 
            
            // Prevent visiting the same node again
            vector<bool> visited(numCourses, false);
            visited[u] = true;
            
            bool found = false; 
            
            while(!q.empty()) { 
                int x = q.front(); 
                q.pop(); 
                for(auto l : adj[x]) { 
                    if(l == v) { 
                        found = true; 
                        break; 
                    } 
                    
                    if(!visited[l]) {
                        visited[l] = true;
                        q.push(l); 
                    }
                } 
                
                if(found) { 
                    ans[i] = true; 
                    break; 
                } 
            } 
        } 
        
        return ans; 
    } 
};