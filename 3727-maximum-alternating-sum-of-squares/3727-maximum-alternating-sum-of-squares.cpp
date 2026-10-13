class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            nums[i] = abs(nums[i]);
        }
        long long sum = 0;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        while(i < j){
            sum += pow(nums[j],2) - pow(nums[i],2);
            j--;
            i++;
        }
        if(i == j){
            sum += pow(nums[j], 2);
        }
        return sum;
    }
};