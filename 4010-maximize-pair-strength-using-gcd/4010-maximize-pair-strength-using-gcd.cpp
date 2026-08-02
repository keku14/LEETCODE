class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                long long g = gcd(nums[i],nums[j]);
                long long x = nums[i]/g;
                long long y = nums[j]/g;
                ans = max(ans,1LL*x*y);
            }
        }
        return ans;
    }
};