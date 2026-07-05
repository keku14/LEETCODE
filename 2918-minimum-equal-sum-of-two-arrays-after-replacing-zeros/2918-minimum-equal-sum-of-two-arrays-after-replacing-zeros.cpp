class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0;
        long long c1 = 0, c2 = 0;

        for (int x : nums1) {
            s1 += x;
            if (x == 0) c1++;
        }

        for (int x : nums2) {
            s2 += x;
            if (x == 0) c2++;
        }

        if (c1 == 0 && c2 == 0) {
            return (s1 == s2) ? s1 : -1;
        }

        if (c1 == 0) {
            if (s2 + c2 > s1) return -1;
            return s1;
        }

        if (c2 == 0) {
            if (s1 + c1 > s2) return -1;
            return s2;
        }

        return max(s1 + c1, s2 + c2);
    }
};