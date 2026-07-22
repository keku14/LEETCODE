class Solution {
    int fn(int idx, vector<int>&nums, int target, int n, map<pair<int,int>,int>&dp){
        //base case
        if(idx==0){
            //0 se 0 tak
            int cnt=0;
            if(target==nums[0]) cnt++; //assign +ve to nums[0]
            if(target==-nums[0]) cnt++; //assign -ve to nums[0]
            return cnt;
        }

        //general case
        if(dp.count({idx,target})) return dp[{idx,target}];

        int plus=fn(idx-1,nums,target-nums[idx],n,dp);
        int minus=fn(idx-1,nums,target+nums[idx],n,dp);
        
        dp[{idx,target}]=plus+minus;
        return dp[{idx,target}];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        //fn(idx)=> idx se 0 tak jaa rha hu
        //idx and target are changing
        //{idx,target} -> -1
        map<pair<int,int>, int>dp;
        return fn(n-1,nums,target,n,dp);
    }
};