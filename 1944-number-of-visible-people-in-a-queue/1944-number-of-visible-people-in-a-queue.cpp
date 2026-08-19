class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st; // Stores heights of people
        
        for (int i = n - 1; i >= 0; --i) {
            int visible_count = 0;
            
            while (!st.empty() && st.top() < heights[i]) {
                st.pop();
                visible_count++;
            }
            if (!st.empty()) {
                visible_count++;
            }
            ans[i] = visible_count;
            st.push(heights[i]);
        }
        
        return ans;
    }
};