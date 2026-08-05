class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>> maxi;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mini;
        int l = 0;
        int ans = 0;
        
        for(int r = 0;r<nums.size();r++){
            maxi.push({nums[r],r});
            mini.push({nums[r],r});
            
            while(true){
                while(maxi.top().second < l){
                    maxi.pop();
                }
                while(mini.top().second < l){
                    mini.pop();
                }
                
                if(maxi.top().first - mini.top().first <= limit) break;
                
                l++;
            }
            
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};