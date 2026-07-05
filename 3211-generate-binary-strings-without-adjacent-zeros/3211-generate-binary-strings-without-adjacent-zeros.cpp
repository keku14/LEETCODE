class Solution {
public:
    void fn(string& s,vector<string>& ans,int n,int idx){
        if(idx == n){
            ans.push_back(s);
            return;
        }
     
        s.push_back('1');
        fn(s,ans,n,idx+1);
        s.pop_back();
        if(idx == 0 || s.back() == '1'){
            s.push_back('0');
            fn(s,ans,n,idx+1);
            s.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string k = "";
        fn(k,ans,n,0);

        return ans;
    }
};