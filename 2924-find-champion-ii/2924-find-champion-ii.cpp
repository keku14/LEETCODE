class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            indegree[v]++;
        }
        int cnt=0;
        int ans=-1;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0) {
                ans=i;
                cnt++;
            }
        }
        if(cnt == 1)  return ans;
        return -1;
    }
};