class Solution {
public:
    bool fn(int idx,string& s,unordered_set<string>& st,vector<int>& dp){
        if(idx == s.length()){
            return true;
        }

        if(dp[idx] != -1) return dp[idx];
        string temp = "";
        for(int i = idx;i<s.length();i++){
            temp += s[i];
            if(st.count(temp)){
                if(fn(i+1,s,st,dp)){
                    dp[idx] = 1;
                    return dp[idx];
                }
            }
        }
        dp[idx] = 0;
        return dp[idx];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto it : wordDict) st.insert(it);
        int n = s.length();
        vector<int> dp(n,-1);
        return fn(0,s,st,dp);
    }
};