class Solution {
public:
    void fn(int x, vector<int>& st){
        for(int i = 2; i * i <= x; i++){
            if(x % i == 0){
                st.push_back(i);
                while(x % i == 0)
                    x /= i;
            }
        }
        if(x > 1) st.push_back(x);
    }

    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> mpp(n);
        for(int i = 0; i < n; i++){
            fn(nums[i], mpp[i]);
        }
        unordered_map<int,int> mp;
        int l = 0;
        int curr = 0;
        int ans = 0;

        for(int r = 0; r < n; r++){
            for(int p : mpp[r]){
                if(mp[p] == 0) curr++;

                mp[p]++;
            }
            while(curr > k){
                for(int p : mpp[l]){
                    mp[p]--;
                    if(mp[p] == 0){
                        mp.erase(p);
                        curr--;
                    }
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};