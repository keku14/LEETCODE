class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        while(r <= n-1){

            if(mp.count(nums[r])){
                //shrink window
                int idx=mp[nums[r]];
                for(int i=l; i<=idx; i++){
                    sum-=nums[i];
                    l++;
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                }
            }
            sum+=nums[r];
            mp[nums[r]]=r;
            ans=max(ans,sum);
            r++;
        }
        return ans;
    }
};