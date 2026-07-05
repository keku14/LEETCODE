class Solution {
public:
    int minChanges(string s) {
        int cnt = 0;
        int n = s.length();

        for(int i = 1;i<n;i++){
            if(i%2 == 1){
                if(s[i] != s[i-1]) cnt++;
            }
        } 
        return cnt;
    }
};