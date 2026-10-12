class Solution {
public:
    bool isprime(int x){
        if(x <= 1) return false;
        if(x == 2) return true;

        if(x%2 == 0) return false;

        for(int i = 3;i*i<=x;i+=2){
            if(x%i == 0) return false;
        }

        return true;
    }
    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;
        int sum = 0;
        for(int i = 2;i<=n;i++){
            if(isprime(i)){
                sum += i;
                if(sum <= s) ans.push_back(i);
                else break;
            }
        }
        return ans;
    }
};