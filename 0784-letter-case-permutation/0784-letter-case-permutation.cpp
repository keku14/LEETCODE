class Solution {
public:
    void fn(string &s, string &k, vector<string> &ans, int index) {
        if (index == s.length()) {
            ans.push_back(k);
            return;
        }

        if (isdigit(s[index])) {
            k.push_back(s[index]);
            fn(s, k, ans, index + 1);
            k.pop_back();
        } else {
            // lowercase
            k.push_back(tolower(s[index]));
            fn(s, k, ans, index + 1);
            k.pop_back();

            // uppercase
            k.push_back(toupper(s[index]));
            fn(s, k, ans, index + 1);
            k.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string k = "";
        fn(s, k, ans, 0);
        return ans;
    }
};