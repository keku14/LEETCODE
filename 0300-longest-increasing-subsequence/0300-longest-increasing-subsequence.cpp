class Solution {
public:
    int fn(int idx, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == nums.size()) {
            return 0;
        }
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int npick = fn(idx+1,prev,nums,dp);
        int pick = 0;

        if(prev == -1 || nums[idx] > nums[prev]){
            pick = 1 + fn(idx+1,idx,nums,dp);
        }

        dp[idx][prev+1] = max(pick,npick);
        return dp[idx][prev+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fn(0, -1, nums, dp);
    }
};