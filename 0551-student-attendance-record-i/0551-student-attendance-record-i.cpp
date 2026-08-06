class Solution {
public:
    bool checkRecord(string s) {
        int cnt = 0;
        int n = s.length();
        bool found = false;
        for(int i = 0;i<n;i++){
            if(s[i] == 'A') cnt++;
            
            if(s[i] == 'L'){
                if(i+2 < n){
                    if(s[i+1] == 'L' && s[i+2] == 'L') return false;
                }
            }
        }
        
        if(cnt >= 2) return false;
        
        return true;
    }
};