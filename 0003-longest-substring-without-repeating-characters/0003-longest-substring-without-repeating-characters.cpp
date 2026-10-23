class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int maxlen = 0;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            if (mpp.count(s[r]) && mpp[s[r]] >= l) {
                l = mpp[s[r]] + 1;
            }

            mpp[s[r]] = r;

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};