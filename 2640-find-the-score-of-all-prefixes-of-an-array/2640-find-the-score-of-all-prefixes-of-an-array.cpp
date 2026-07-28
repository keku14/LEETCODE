class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pref(n);
        long long maxi=nums[0];
        for(int i=0; i<=n-1; i++){
            maxi=max(maxi,(long long)nums[i]);
            pref[i]=nums[i]+maxi;
        }

        vector<long long> ans(n);
        long long sum=0;
        for(int i=0; i<pref.size(); i++){
            sum+=(long long)pref[i];
            ans[i]=sum;
        }
        return ans;
    }
};