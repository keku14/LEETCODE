class Solution {
public:
    bool fn(int i, int j, int p1, int p2, vector<int>& nums, bool k){
        if(i > j){
            return p1 >= p2;
        }

        if(k){
            return fn(i+1, j, p1 + nums[i], p2, nums, false) || fn(i, j-1, p1 + nums[j], p2, nums, false);
        }
        else{
            return fn(i+1, j, p1, p2 + nums[i], nums, true) && fn(i, j-1, p1, p2 + nums[j], nums, true);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        return fn(0, nums.size()-1, 0, 0, nums, true);
    }
};