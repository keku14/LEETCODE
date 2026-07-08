class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        vis[0] = 1;

        while(!q.empty()){
            int x = q.front();
            q.pop();

            for(auto it : rooms[x]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

        for(auto it : vis){
            if(it == 0) return false;
        }
        return true;
    }
};