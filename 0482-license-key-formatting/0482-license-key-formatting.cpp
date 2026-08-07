class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string temp = "";
        for(char c : s){
            if(c != '-'){
                temp.push_back(toupper(c));
            }
        }
        int n = temp.size();
        int first = n%k;
        string ans = "";
        int i = 0;
        
        if(first){
            ans += temp.substr(0,first);
            i = first;
            if(i < n) ans.push_back('-');
        }
        
        while(i < n){
            ans += temp.substr(i,k);
            i += k;
            if(i < n) ans.push_back('-');
        }
        
        return ans;
    }
};