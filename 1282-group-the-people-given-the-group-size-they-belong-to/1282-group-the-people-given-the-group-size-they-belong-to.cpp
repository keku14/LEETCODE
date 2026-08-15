class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int,vector<int>> mpp;
        for(int i = 0;i<n;i++){
            mpp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> v;
        // for(auto it : mpp){
        //     cout << it.first << endl;
        //     for(auto &i : it.second){
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        for(auto it : mpp){
            vector<int> k = it.second;
            int size = it.first;

            vector<int> ans;
            for(int i = 0;i<k.size();i++){
                if(ans.size() == size){
                    v.push_back(ans);
                    ans.clear();
                }
                ans.push_back(k[i]);
            }
            v.push_back(ans);
        }
        return v;
    }
};