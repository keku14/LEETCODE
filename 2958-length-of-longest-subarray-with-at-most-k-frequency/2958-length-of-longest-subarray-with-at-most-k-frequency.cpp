class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int maxi = 0;
        int ans = 0;
        int n=nums.size();
        unordered_map<int,int> mpp;
        while(r <= n-1){
            if(!mpp.count(nums[r])){
                mpp[nums[r]] = 1;
            }else{
                int x = mpp[nums[r]];
                if(x+1 > k){
                    while(l < r){
                        if(nums[l] == nums[r]){
                            mpp[nums[l]]--;
                            l++;
                            break;
                        }
                        mpp[nums[l]]--;
                        l++;
                    }
                }
                    mpp[nums[r]]++;
                
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};