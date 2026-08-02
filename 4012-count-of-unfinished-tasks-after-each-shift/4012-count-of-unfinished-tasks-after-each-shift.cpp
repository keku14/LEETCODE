class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> pref(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += tasks[i];
            pref[i] = sum;
        }

        vector<int> ans;
        long long target = 0;

        for (auto it : shifts) {
            if (it >= sum - target) {
                ans.push_back(0);
                target = 0;
                continue;
            }

            target += it;

            int s = 0, e = n - 1;
            int last = -1;

            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (pref[mid] <= target) {
                    last = mid;
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }

            ans.push_back(n - last - 1);
        }
        return ans;
    }
};