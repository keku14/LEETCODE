class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0;
        int close = 0;
        int maxi = 0;
        for(auto it : s){
            if(it == '(') open++;
            else close++;

            if(open == close){
                maxi = max(maxi,open*2);
            }else if(close > open){
                open = 0;
                close = 0;
            }
        }

        open = 0;
        close = 0;
        for(int i = s.length()-1;i>=0;i--){
            if(s[i] == '(') open++;
            else close++;

            if(open == close){
                maxi = max(maxi,open*2);
            }else if(close < open){
                open = 0;
                close = 0;
            }
        }

        return maxi;
    }
};