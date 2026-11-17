class Solution {
public:
    int fn(int mid, vector<int>& piles){
        int cnt = 0;
        for(auto it : piles){
            if(it%mid == 0){
                cnt += it/mid;
            }else{
                cnt += it/mid + 1;
            }
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = INT_MIN;
        for(auto it : piles){
            e = max(e,it);
        }
        int ans = INT_MAX;
        while(s <= e){
            int mid = e + (s-e)/2;
            if(fn(mid,piles) <= h){
                ans = min(ans,mid);
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};