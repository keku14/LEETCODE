class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> v;
        long long sum = 0, num = 0;

        while (n > 0) {
            int x = n % 10;
            if (x != 0) {
                v.push_back(x);
            }
            n /= 10;
        }

        reverse(v.begin(), v.end());

        for (auto digit : v) {
            sum += digit;
            num = num * 10 + digit;
        }

        return sum * num;
    }
};