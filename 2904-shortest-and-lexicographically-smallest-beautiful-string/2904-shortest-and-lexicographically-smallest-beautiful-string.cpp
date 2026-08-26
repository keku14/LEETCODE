class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string res = "";
        int l = 0;
        int r = 0;
        string curr = "";
        int cnt = 0;
        while(r < n){
            if(s[r] == '1') cnt++;
            while(cnt > k){
                if(s[l] == '1') cnt--;

                l++;
            }

            if(cnt == k){
                while(s[l] == '0') l++;
                string temp = "";
                for(int i = l;i<=r;i++) temp += s[i];
                if(curr == "" || curr.size() > temp.size() || (curr.size() == temp.size() && temp < curr)){
                    curr = temp;
                }
            }
            r++;
        }
        return curr;
    }
};