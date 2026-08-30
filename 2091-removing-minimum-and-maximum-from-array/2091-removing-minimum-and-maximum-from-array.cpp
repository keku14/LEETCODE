class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        int n = nums.size();
        for(auto it : nums){
            mini = min(mini,it);
            maxi = max(maxi,it);
        }

        int idx1 = 0;
        int idx2 = 0;

        for(int i = 0;i<n;i++){
            if(nums[i] == maxi || nums[i] == mini){
                idx1 = i;
                break;
            }
        }
        for(int i = n-1;i>=0;i--){
            if(nums[i] == maxi || nums[i] == mini){
                idx2 = i;
                break;
            }
        }
        int ans = INT_MAX;
        ans = min(ans,n-idx1);
        ans = min(ans,idx2+1);

        int a = idx1+1;
        int b = n-idx2;
        ans = min(ans,a+b);

        return ans;
    }
};