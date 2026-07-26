class Solution {
public:
    int largestInteger(int n, int s) {
        if(n*9 < s) return -1;

        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j=9;j>=0;j--){
                if(j <= s){
                    ans = ans*10 + j;
                    s -= j;
                    break;
                }
            }
        }
        return ans;
    }
};