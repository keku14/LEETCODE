class Solution {
public:
    int fn(vector<int>& coins,int amount,int idx,vector<vector<int>>& dp){
        if(amount == 0){
            return 0;
        }

        if(idx == 0){
            if(amount % coins[0] == 0){
                return amount/coins[0];
            }
            return 1e8;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];

        int pick = 1e8;
        if(coins[idx] <= amount) pick = 1 + fn(coins,amount-coins[idx],idx,dp);

        int npick = fn(coins,amount,idx-1,dp);

        return dp[idx][amount] = min(pick,npick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = fn(coins,amount,n-1,dp);
        return (ans == 1e8) ? -1 : ans;
    }
};