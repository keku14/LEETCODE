class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        priority_queue<pair<int,int>> pq;
        int n = restaurants.size();
        for(int i = 0;i<n;i++){
            if(((restaurants[i][2] == veganFriendly) || !veganFriendly) && (restaurants[i][3] <= maxPrice) && (restaurants[i][4] <= maxDistance)){
                pq.push({restaurants[i][1],restaurants[i][0]});
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            int x = pq.top().second;
            ans.push_back(x);
            pq.pop();
        }
        return ans;
    }
};