class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == ')') {
                string k = "";
                
                
                while (!st.empty() && st.top() != '(') {
                    k += st.top();
                    st.pop();
                }
                st.pop(); 
                
        
                for (char ch : k) {
                    st.push(ch);
                }
            } else {
                st.push(c);
            }
        }
        
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
