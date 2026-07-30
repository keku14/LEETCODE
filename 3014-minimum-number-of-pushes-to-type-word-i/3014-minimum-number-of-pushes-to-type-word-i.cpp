class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n>=1 && n<=8) return n;
        if(n>8 && n<=16){
            int ans=8+(n-8)*2;
            return ans;
        }
        if(n>16 && n<=24){
            int ans=8+8*2+(n-16)*3;
            return ans;
        }
        if(n>24 && n<=26){
            int ans=8+8*2+8*3+(n-24)*4;
            return ans;
        }
        return n;
    }
};