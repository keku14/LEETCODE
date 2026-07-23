class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto it : nums) mpp[it]++;

        int maj = INT_MIN;
        int ele = -1;
        for(auto it : mpp){
            if(it.second > maj){
                maj = it.second;
                ele = it.first;
            }
        }
        
        unordered_map<int,int> temp;
        for(int i = 0;i<n;i++){
            temp[nums[i]]++;
            mpp[nums[i]]--;

            if(mpp[nums[i]] == 0) mpp.erase(nums[i]);

            int len = i+1;
            int lenp = n - i - 1;
            
            if(temp[ele] > len/2 && mpp[ele] > lenp/2){
                return i;
            }
        }
        return -1;
    }
};