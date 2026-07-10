class Solution {
public:
    bool isHappy(int n) {
        int x = n;
        while(n/10 != 0){
            int num = 0;
            while(x){
                int digi = x%10;
                num += digi*digi;
                x /= 10;
            }
            x = num;
            n = x;
        }
        return (n == 1 || n == 7);
    }
};