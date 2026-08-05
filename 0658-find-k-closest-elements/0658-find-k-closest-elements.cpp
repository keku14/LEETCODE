class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<pair<int,int>> v;

        for(int i = 0;i<n;i++){
            v.push_back({abs(arr[i] - x),i});
        }

        sort(v.begin(),v.end());

        vector<int> ans;
        int s = 0;
        for(auto it : v){
            if(s == k) break;
            ans.push_back(arr[it.second]);
            s++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};