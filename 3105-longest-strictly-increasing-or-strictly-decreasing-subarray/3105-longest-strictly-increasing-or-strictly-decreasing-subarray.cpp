class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int a = 1;
        int b = 1;
        int n = nums.size();
        int cnt = 1;
        for(int i = 1;i<n;i++){
            if(nums[i] > nums[i-1]){
                cnt++;
                a = max(a,cnt);
            }else{
                cnt = 1;
            }
        }
        cnt = 1;
        for(int i = 1;i<n;i++){
            if(nums[i] < nums[i-1]){
                cnt++;
                b = max(b,cnt);
            }else{
                cnt = 1;
            }
        }
        return max(a,b);
    }
};