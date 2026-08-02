class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int ans = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            int cnto = 0;
            int cnte = 0;
            for(int j = i;j<n;j++){
                if(nums[j]%2 == 0) cnte++;
                else cnto++;

                if(cnto > 0 && ((1ll*cnte*b) <= (1ll*a*cnto))) ans++;
            }
        }
        return ans;
    }
};