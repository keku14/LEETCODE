class Solution {
public:
    void fn(vector<int>& nums,int idx,int curr,int n,int& sum){
        if(idx == n){
            sum += curr;
            return;
        }

        fn(nums,idx+1,curr^nums[idx],n,sum);
        fn(nums,idx+1,curr,n,sum);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        fn(nums,0,0,n,sum);
        return sum;
    }
};