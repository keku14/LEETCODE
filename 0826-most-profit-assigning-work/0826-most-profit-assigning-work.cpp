class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int n = difficulty.size();
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i],difficulty[i]});
        }
        sort(jobs.begin(), jobs.end());
        sort(difficulty.begin(), difficulty.end());
        sort(worker.begin(), worker.end());

        int j = 0;
        int ans = 0;
        int i = difficulty.size() -1;
        while (j < worker.size() && i >=0 ) {
            if(worker[j] < difficulty[0]){
                j++;
            }
            else if(worker[j] >= jobs[i].second){
                ans += jobs[i].first;
                j++;
                i = difficulty.size() -1;
            }
            else i--;
        }
        return ans;
    }
};