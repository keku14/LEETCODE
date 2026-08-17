class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        unordered_map<int,int> mpp;
        for(auto it : nums){
            maxi = max(maxi,it);
            mpp[it]++;
        }

        vector<int> ans;
        for(int i = 0;i<n;i++){
            int x = nums[i];
            if(mpp[x] == 1){
                if(!mpp.count(x-1) && !mpp.count(x+1)) ans.push_back(x);
            }
        }
        return ans;
    }
};