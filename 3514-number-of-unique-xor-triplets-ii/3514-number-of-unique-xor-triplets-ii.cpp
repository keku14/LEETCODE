class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(int i=0; i<=n-1; i++){
            for(int j=i; j<=n-1; j++){
                st.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> st1;
        for(int i=0; i<n; i++){
            for(auto it: st){
                st1.insert(it^nums[i]);
            }
        }
        return st1.size();
    }
};