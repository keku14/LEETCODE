class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = 0;
        unordered_map<int,int> mpp;
        for(auto it : nums){
            mini = min(mini,it);
            maxi = max(maxi,it);
            mpp[it]++;
        }
        vector<int> ans;
        while(mini <= maxi){
            if(!mpp.count(mini)){
                ans.push_back(mini);
            }
            mini++;
        }
        return ans;
    }
};