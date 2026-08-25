class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        int n = tickets.size();
        int t = 0;
        for(int i = 0;i<n;i++){
            q.push({tickets[i],i});
        }

        while(!q.empty()){
            t++;
            int tic = q.front().first;
            int idx = q.front().second;
            q.pop();
            if(idx == k && tic-1 == 0) return t;

            if(tic-1 > 0) q.push({tic-1,idx});
        }
        return 0;
    }
};