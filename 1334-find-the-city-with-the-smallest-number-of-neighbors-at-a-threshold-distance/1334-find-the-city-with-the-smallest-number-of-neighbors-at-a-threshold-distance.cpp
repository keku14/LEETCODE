class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));

        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] != 1e8 && dist[via][j] != 1e8) {
                        dist[i][j] =
                            min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
        int idx = -1;
        int ans = 1e8;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) cnt++;
            }
            if (cnt <= ans) {
                ans = cnt;
                idx = i;
            }
        }
        return idx;
    }
};