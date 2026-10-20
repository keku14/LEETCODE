class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        vector<int> x = nums;
        int n = nums.size();
        int ans = 0;
        for(int k = 1;k<=n;k++){
            if(n%k!=0) continue;

            
            bool possible = true;
            long long prev = -2e9;
            for(int start = 0;start<n;start+=k){
                int drops = 0;
                int drop_indx = -1;
                for(int i = 0;i<k;i++){
                    int curr = x[start+i];
                    int next = x[start + (i+1)%k];

                    if(curr > next){
                        drops++;
                        drop_indx = i;
                    }
                }
                if(drops > 1){
                    possible = false;
                    break;
                }
                int first,last;
                if(drops == 0){
                    first = x[start];
                    last = x[start+k-1];
                }else{
                    first = x[start + (drop_indx+1)%k];
                    last = x[start+drop_indx];
                }

                if(first < prev){
                    possible = false;
                    break;
                }
                prev = last;
            }
            if(possible) ans += k;
        }
        return ans;
    }
};
// vector<int> x;
            // for(int start = 0;start<n;start+=k){
            //     int end = start+k;

            //     int mini = start;
            //     for(int i= start;i<end;i++){
            //         if(nums[i] < nums[mini]){
            //             mini = i;
            //         }
            //     }
            //     int rel = mini - start;
            //     for(int i = 0;i<k;i++){
            //         x.push_back(nums[(rel+i)%k + start]);
            //     }
            // }
            // bool ok = true;
            // for(int i = 1;i<n;i++){
            //     if(x[i] < x[i-1]){
            //         ok = false;
            //         break;
            //     }
            // }
            // if(ok) ans+=k;