class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int cnt = 0;
        int curr = nums[0];
        for(int i = 1;i<nums.size();i++){
            int x = curr ^ nums[i];
            if(x == 0) cnt++;
            else curr = nums[i];
        }
        return cnt;
    }
};