class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> st;
        int cnt = 0;
        int sum = 0;

        for (int i = 1; cnt < n; i++) {
            if (!st.count(k - i)) {
                st.insert(i);
                sum += i;
                cnt++;
            }
        }

        return sum;
    }
};