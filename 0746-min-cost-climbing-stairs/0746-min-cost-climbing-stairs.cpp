class Solution {
public:
    int fn(vector<int>& cost, int idx, vector<int>& dp) {
        if (idx == 0) return cost[0];
        if (idx == 1) return cost[1];

        if (dp[idx] != -1)
            return dp[idx];

        return dp[idx] = cost[idx] + min(fn(cost, idx - 1, dp),fn(cost, idx - 2, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        return min(fn(cost, n - 1, dp), fn(cost, n - 2, dp));
    }
};