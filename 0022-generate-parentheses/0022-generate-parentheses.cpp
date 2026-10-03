class Solution {
public:

bool valid(string &s){
    int cnt = 0;
    for(auto it : s){
        if(it == '(') cnt++;
        else{
            if(cnt-1 < 0) return false;
            cnt--;
        }
    }
    return true;
}

void f(int open,int close,vector<string>&output,string s,int cnt){
    if(open==0 && close==0){
        // bool check = valid(s);
        // if(check) 
        output.push_back(s);
        return;
    }

    if(open!=0 && close==0)return;
    if(open>0)f(open-1,close,output,s+"(",cnt+1);
    if(close>0 &&  cnt-1 >= 0)f(open,close-1,output,s+")",cnt-1);
    return;
}

    vector<string> generateParenthesis(int n) {
        vector<string>output;
        string s = "";
        f(n,n,output,s,0);
        return output;
    }
};