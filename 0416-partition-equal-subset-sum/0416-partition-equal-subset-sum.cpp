class Solution {
public:
    bool fn(vector<int>& nums,int target,int idx,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(idx == 0){
            if(target == nums[idx]) return true;
            return false;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        
        bool pick = false;
        if(nums[idx] <= target) pick = fn(nums,target-nums[idx],idx-1,dp);
        bool npick = fn(nums,target,idx-1,dp);

        return dp[idx][target] = pick || npick;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(auto it : nums){
            total += it;
        }
        if (total % 2 != 0) return false;
        int target = total/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return fn(nums,target,n-1,dp);
    }
};