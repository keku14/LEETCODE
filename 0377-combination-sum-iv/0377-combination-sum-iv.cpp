class Solution {
public:
    int fn(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) return 1;
        int ans = 0;

        if(dp[target] != -1) return dp[target];
        for (int x : nums) {
            if (x <= target) {
                ans += fn(nums, target - x, dp);
            }
        }
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return fn(nums, target, dp);
    }
};