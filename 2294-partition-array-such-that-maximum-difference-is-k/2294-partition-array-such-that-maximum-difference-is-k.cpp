class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mini=nums[0];
        int cnt=1;
        for(int i=0; i<=n-1; i++){
            if(nums[i]-mini >k){
                cnt++;
                mini=nums[i];
            }
        }
        return cnt;
    } 
};