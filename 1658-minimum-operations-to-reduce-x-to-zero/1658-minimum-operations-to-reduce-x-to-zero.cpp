class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for(auto it : nums){
            total += it;
        }

        int target = total - x;
        if(target < 0) return -1;
        if(target == 0) return n;
        int i = 0;
        int sum = 0;
        int len = -1;

        for(int j = 0;j<n;j++){
            sum += nums[j];

            while(i <= j && sum > target){
                sum -= nums[i];
                i++;
            }

            if(sum == target){
                len = max(len,j-i+1);
            }
        }
        return (len == -1) ? -1 : n - len;
    }
};