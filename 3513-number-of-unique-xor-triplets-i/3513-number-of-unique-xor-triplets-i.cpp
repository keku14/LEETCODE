class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return n;

        int nearest = (int)(log2(n));
        return 1 << (nearest + 1);
    }
};