class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int x = nums[i];
            int mini = INT_MAX;
            for(int j = i;j<n;j++){
                mini = min(mini,nums[j]);
                x &= nums[j];

                if(x == mini) cnt++;
            }
        }
        return cnt;
    }
};