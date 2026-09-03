class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        for(auto it : nums1){
            mini = min(mini,it);
        }

        if(mini%2== 1) return true;

        for(auto x : nums1){
            if(x%2 == 1) return false;
        }

        return true;
    }
};