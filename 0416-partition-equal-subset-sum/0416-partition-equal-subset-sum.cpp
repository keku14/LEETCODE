//Memoization
// class Solution {
// public:
//     bool fn(vector<int>& nums,int target,int idx,vector<vector<int>>& dp){
//         if(target == 0) return true;
//         if(idx == 0){
//             if(target == nums[idx]) return true;
//             return false;
//         }
//         if(dp[idx][target] != -1) return dp[idx][target];

//         bool pick = false;
//         if(nums[idx] <= target) pick = fn(nums,target-nums[idx],idx-1,dp);
//         bool npick = fn(nums,target,idx-1,dp);

//         return dp[idx][target] = pick || npick;
//     }
//     bool canPartition(vector<int>& nums) {
//         int total = 0;
//         int n = nums.size();
//         for(auto it : nums){
//             total += it;
//         }
//         if (total % 2 != 0) return false;
//         int target = total/2;
//         vector<vector<int>> dp(n,vector<int>(target+1,-1));
//         return fn(nums,target,n-1,dp);
//     }
// };


//Tabulation
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int total = 0;
//         int n = nums.size();
//         for (auto it : nums) {
//             total += it;
//         }
//         if (total % 2 != 0)
//             return false;
//         int target = total / 2;
//         vector<vector<bool>> dp(n, vector<bool>(target+1, false));

//         for (int i = 0; i < n; i++) {
//             dp[i][0] = true;
//         }
//         for (int i = 1; i < n; i++) {
//             for (int j = 1; j <= target; j++) {
//                 if (i == n - 1) {
//                     if (j == nums[i])
//                         dp[i][j] = true;
//                     dp[i][j] = false;
//                 }
//                 bool pick = false;
//                 if (nums[i] <= j)
//                     pick = dp[i-1][j - nums[i]];
//                 bool npick = dp[i-1][j];

//                 dp[i][j] = pick || npick;
//             }
//         }
//         return dp[n - 1][target];
//     }
// };


//Space opt
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (auto it : nums) {
            total += it;
        }
        if (total % 2 != 0)
            return false;
        int target = total / 2;
        vector<bool> prev(target+1, false);
        prev[0] = true;
        for (int i = 1; i < n; i++) {
            vector<bool> temp(target+1,false);
            temp[0] = true;
            for (int j = 1; j <= target; j++) {
                if (i == n - 1) {
                    if (j == nums[i])
                        temp[j] = true;
                    temp[j] = false;
                }
                bool pick = false;
                if (nums[i] <= j)
                    pick = prev[j - nums[i]];
                bool npick = prev[j];

                temp[j] = pick || npick;
            }
            prev = temp;
        }
        return prev[target];
    }
};