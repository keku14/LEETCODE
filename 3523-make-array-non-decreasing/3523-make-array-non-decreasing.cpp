class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        st.push(nums[0]);
        for(int i = 1;i<n;i++){
            int x = st.top();
            //int j = -1;
            if(nums[i] >= x){
                st.push(nums[i]);
                //continue;
            }
        }
        return st.size();
    }
};