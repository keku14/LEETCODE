class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mpp;
        for(auto it : knowledge){
            mpp[it[0]] = it[1];
        }

        string ans = "";
        for(int i = 0;i<s.length();i++){
            if(s[i] == '('){
                int j = i+1;
                string temp = "";
                while(s[j] != ')'){
                    temp += s[j];
                    j++;
                }
                if(mpp.count(temp)){
                    ans += mpp[temp];
                }else{
                    ans += "?";
                }
                i = j;
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};