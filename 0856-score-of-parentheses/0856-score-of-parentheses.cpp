class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == '(') {
                st.push(-1); // mark '(' with -1
            } else if (ch == ')') {
                if (!st.empty() && st.top() == -1) {
                    st.pop();
                    st.push(1); // "()" → score = 1
                } else {
                    int sum = 0;
                    while (!st.empty() && st.top() != -1) {
                        sum += st.top();
                        st.pop();
                    }
                    st.pop();         // remove '(' marker
                    st.push(2 * sum); // wrap inside ( )
                }
            }
        }

        // final sum
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};