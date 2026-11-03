class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MIN;
        for(auto it : nums){
            maxi = max(maxi,it);
        }
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            ans += abs(maxi-nums[i]);
        }
        return ans;
    }
};