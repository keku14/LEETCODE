class Solution {
public:
    int fn(vector<int>& nums, int mid){
        int res = 0;
        for(auto it : nums){
            if(it%mid == 0){
                res += it/mid;
            }else{
                res += (it/mid) + 1;
            }
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = INT_MIN;
        for(auto it : nums){
            //s = min(s,it);
            e = max(e,it);
        }
        
        int ans = INT_MAX;
        while(s <= e){
            int mid = e + (s-e)/2;
            int x = fn(nums,mid);

            if(x <= threshold){
                ans = min(ans,mid);
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};