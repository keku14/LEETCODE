class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //vector<int> ans;
        unordered_map<int,int> mpp;
        mpp[nums[0]] = 0;
        for(int i=1;i<nums.size();i++){
            int x = target - nums[i];
            if(mpp.count(x)){
                //ans.push_back(mpp[x]);
                //ans.push_back(i);
                return {mpp[x],i};
                break;
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};