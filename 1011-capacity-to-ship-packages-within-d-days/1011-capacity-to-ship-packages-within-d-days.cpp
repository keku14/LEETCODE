class Solution {
public:
    int fn(int mid,vector<int>& arr){
        int cnt = 1;
        int sum = 0;
        for(int i = 0;i<arr.size();i++){
            if(sum + arr[i] <= mid){
                sum += arr[i];
            }else{
                cnt++;
                sum = arr[i];
            }
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0;
        int e = 0;
        for(auto it : weights){
            s = max(s,it);
            e += it;
        }


        int ans = INT_MAX;
        while(s <= e){
            int mid = e + (s-e)/2;
            if(fn(mid,weights) <= days){
                ans = min(ans,mid);
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};