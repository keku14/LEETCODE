// class Solution {
// public:
//     void fn(int idx, int start, int &cnt, int n) {
//         if (idx == n) {
//             cnt++;
//             return;
//         }

//         for (int i = start; i < 5; i++) {
//             fn(idx + 1, i, cnt, n);
//         }
//     }

//     int countVowelStrings(int n) {
//         int cnt = 0;
//         fn(0, 0, cnt, n);
//         return cnt;
//     }
// };

class Solution {
    int fn(int len, int last, int n, vector<vector<int>>& dp) {
        if (len == n)
            return 1;

        if (dp[len][last] != -1)
            return dp[len][last];

        int ans = 0;

        for (int i = last; i < 5; i++) {
            ans += fn(len + 1, i, n, dp);
        }

        return dp[len][last] = ans;
    }

public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(5, -1));
        return fn(0, 0, n, dp);
    }
};