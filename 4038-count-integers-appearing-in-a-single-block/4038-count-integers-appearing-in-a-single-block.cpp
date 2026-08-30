class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        int n = nums.size();
        for(int i =0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        int cnt = 0;
        for(auto it : mpp){
            vector<int> temp = it.second;
            bool ok = true;
            for(int i =0;i<temp.size()-1;i++){
                if(temp[i]+1 != temp[i+1]){
                    ok = false;
                    break;
                } 
            }
            if(ok) cnt++;
        }
        return cnt;
    }
};