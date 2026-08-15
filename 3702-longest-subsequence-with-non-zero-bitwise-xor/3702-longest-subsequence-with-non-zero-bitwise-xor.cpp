class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool check = true;
        int total = 0;
        for(int i =0;i<nums.size();i++) {
            total ^= nums[i];
            if(nums[i] != 0) check = false;
        }

        if(check) return 0;
        
        if(total != 0) {
            return n;
        }

        return n-1;
    }
};