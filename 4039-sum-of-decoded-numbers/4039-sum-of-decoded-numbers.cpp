class Solution {
public:
    const int MOD = 1e9 + 7;
    long long fn(long long base,long long exp){
        long long res = 1;
        base %= MOD; 
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            long long x = nums[i];
            
            int width = x%10;
            long long d = x/10;
            long long l = d;
            vector<int> temp;
            while(l > 0){
                temp.push_back(l%10);
                l/=10;
            }
            reverse(temp.begin(),temp.end());

            long long a = 0;
            long long b = 0;
            for(int j = 0;j<width;j++){
                a = a*10 + temp[j];
            }
            for(int j = width;j<temp.size();j++){
                b = b*10 + temp[j];
            }

            long long res = fn(a,b);
            ans += (res%MOD);
            ans = ans%MOD;
        }
        return (int)ans;
    }
};