class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        threshold *= k;
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < k; i++) sum += arr[i];

        int s = 0;
        int e = k - 1;

        if (sum >= threshold) cnt++;
        while (e + 1 < n) {
            sum -= arr[s];
            sum += arr[e + 1];
            s++;
            e++;

            if (sum >= threshold) cnt++;
        }

        return cnt;
    }
};