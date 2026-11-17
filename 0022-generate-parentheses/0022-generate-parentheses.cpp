class Solution {
public:
    void f(int open,int close,vector<string>&output,string s){
        if(open < 0 || close < 0) return;
        if(open==0 && close==0){
            output.push_back(s);
            return;
        }
    
        if(open!=0 && close==0)return;
        if(open>0) f(open-1,close,output,s+"(");
        if(close>0 && close > open) f(open,close-1,output,s+")");
    }

    vector<string> generateParenthesis(int n) {
        vector<string>output;
        string s = "";
        f(n,n,output,s);

        return output;
    }
};