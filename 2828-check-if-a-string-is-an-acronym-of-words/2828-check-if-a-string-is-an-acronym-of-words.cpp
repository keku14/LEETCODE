class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string k = "";
        for(auto it : words){
            k += it[0];
        }

        return (k == s);
    }
};