class Solution {
public:
    int fn(vector<int>& coins, int idx, int target,vector<vector<int>>& dp){
        if(target == 0) return 0;

        if(idx == 0){
            if(target % coins[0] == 0)
                return target / coins[0];
            return 1e9;
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int npick = fn(coins, idx - 1, target, dp);

        int pick = 1e9;
        if(coins[idx] <= target)
            pick = 1 + fn(coins, idx, target - coins[idx], dp);

        return dp[idx][target] = min(pick, npick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = fn(coins, coins.size() - 1, amount,dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};