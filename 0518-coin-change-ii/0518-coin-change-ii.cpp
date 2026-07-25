// class Solution {
// public:
//     int fn(vector<int>& coins, int idx, int amount, vector<vector<int>>& dp) {
//         if (amount == 0)
//             return 1;

//         if (idx == 0) {
//             return (amount % coins[0] == 0) ? 1 : 0;
//         }

//         if (dp[idx][amount] != -1)
//             return dp[idx][amount];

//         int npick = fn(coins, idx - 1, amount, dp);

//         int pick = 0;
//         if (coins[idx] <= amount) {
//             pick = fn(coins, idx, amount - coins[idx], dp);
//         }

//         return dp[idx][amount] = pick + npick;
//     }

//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
//         return fn(coins, n - 1, amount, dp);
//     }
// };

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 0; j <= amount; j++) {
            dp[0][j] = (j % coins[0] == 0) ? 1 : 0;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                unsigned int npick = dp[i - 1][j];

                unsigned int pick = 0;
                if (coins[i] <= j) {
                    pick = dp[i][j - coins[i]];
                }

                dp[i][j] = pick + npick;
            }
        }

        return dp[n - 1][amount];
    }
};