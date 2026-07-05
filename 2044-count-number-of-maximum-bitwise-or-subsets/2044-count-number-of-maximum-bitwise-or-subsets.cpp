class Solution {
public:
    void fn(vector<int>& nums,int idx,int curr,int& m,vector<int>& v){
        if(idx == nums.size()){
            m = max(m,curr);
            v.push_back(curr);
            return;
        }

        fn(nums,idx+1,curr|nums[idx],m,v);
        fn(nums,idx+1,curr,m,v);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> v;
        int m = INT_MIN;
        fn(nums,0,0,m,v);
        int ans = 0;
        for(auto it : v){
            if(it == m) ans++;
        }
        return ans;
    }
};