// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0)
//             return 0; // nothing to rob
//         if (n == 1)
//             return nums[0]; // only 1 house to rob
//         vector<int> dp(n, -1);

//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);

//         // idx = 0 to n-1
//         for (int i = 2; i < n; i++) {
//             int pick = nums[i] + dp[i - 2]; // Rob this house + best till i-2
//             int notpick = dp[i - 1];        // Skip this house
//             dp[i] = max(pick, notpick);
//         }

//         return dp[n-1];
//     }
// };


// class Solution {
// public:
//     int fn(vector<int>& nums,vector<int>& dp,int idx){
//         if(idx == 0) return nums[0];

//         if(idx < 0) return 0;
//         if(dp[idx] != -1) return dp[idx];

//         int pick = nums[idx] + fn(nums,dp,idx-2);
//         int nonp = fn(nums,dp,idx-1);

//         return dp[idx] = max(pick,nonp);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         return fn(nums,dp,n-1);
//     }
// };



//space opt
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0)
//             return 0; // nothing to rob
//         if (n == 1)
//             return nums[0]; // only 1 house to rob

//         int prev2 = nums[0];
//         int prev= max(nums[0], nums[1]);

//         // idx = 0 to n-1
//         for (int i = 2; i < n; i++) {
//             int pick = nums[i] + prev2; // Rob this house + best till i-2
//             int notpick = prev;        // Skip this house
//             int curri = max(pick, notpick);

//             prev2 = prev;
//             prev = curri;
//         }

//         return prev;
//     }
// };

class Solution {
    int fn(int idx, vector<int>&nums, int n,vector<int>&dp){
        //n-> size of nums
        if(idx >= n) return 0;
        if(idx==n-1) return nums[idx];

        if(dp[idx] != -1) return dp[idx];
        //general idx
        int pick=nums[idx]+fn(idx+2,nums,n,dp); //idx pe khade hoke kya options hai, idx+2 pe jaaunga
        int npick=0+fn(idx+1,nums,n,dp); //idx ko pick nhi kiya hai, ab kya option hai, idx+1 pe jaaunga
        dp[idx]=max(pick,npick);
        return dp[idx];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        //0 to n-1 jaaunga
        //fn(idx)=> idx se n-1 tak max money
        return fn(0,nums,n,dp);
    }
};