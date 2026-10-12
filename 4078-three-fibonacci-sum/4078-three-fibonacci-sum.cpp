class Solution {
public:
    bool threeFibonacciSum(int n) {
        if(n%2!=0) return false;
        int x = n / 2;
        int a = 0;
        int b = 1;
        while(a+b < x){
            int sum = a + b;
            a = b;
            b = sum;
        }

        if(a+b == x) return true;
        else return false;
    }
};