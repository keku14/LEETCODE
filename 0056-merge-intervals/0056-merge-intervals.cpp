class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int i = 0;
        while(i < intervals.size()){
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            while(i < intervals.size()-1 && end >= intervals[i+1][0]){
                if(end < intervals[i+1][1]){
                    end = intervals[i+1][1];
                }
                i++;
            }
            ans.push_back({start,end});
            i++;
        }
        return ans;
    }
};