class Solution {
public:
    int mySqrt(int x) {
        int s = 1;
        int e = x;
        int ans = 0;
        while(s <= e){
            long long mid = e + (s-e)/2;
            if(mid*mid == (long long)x){
                return mid;
            }else if(mid*mid > (long long)x){
                e = mid - 1;
            }else{
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }
};