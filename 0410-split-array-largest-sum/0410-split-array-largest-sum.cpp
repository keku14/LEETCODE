class Solution {
public:
    bool fn(vector<int>& nums,int mid,int k){
        int cnt = 1;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }else{
                sum = nums[i];
                cnt++;
            }
        }

        return (cnt <= k);
    }
    int splitArray(vector<int>& nums, int k) {
        int mini = INT_MIN;
        int maxi = 0;
        for(auto it : nums){
            mini = max(mini,it);
            maxi += it;
        }
        
        int ans = INT_MAX;
        while(mini <= maxi){
            int mid = maxi + (mini - maxi)/2;

            if(fn(nums,mid,k)){
                ans = min(ans,mid);
                maxi = mid - 1;
            }else{
                mini = mid + 1;
            }
        }
        return ans;
    }
};