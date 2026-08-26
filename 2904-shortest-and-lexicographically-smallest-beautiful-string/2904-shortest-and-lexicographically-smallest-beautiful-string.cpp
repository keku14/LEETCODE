class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string res = "";
        for(int i = 0;i<n;i++){
            string l = "";
            int cnt = 0;
            for(int j = i;j<n;j++){
                l += s[j];
                if(s[j] == '1') cnt++;

                if(cnt == k){
                    if(res == "" || l.length() < res.length() ||
                       (l.length() == res.length() && l < res)) {
                        res = l;
                    }
                }else if(cnt > k) break;
            }
        }
        return res;
    }
};