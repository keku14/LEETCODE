class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int idx=1;
        int n=nums.size();
        int sum=nums[0];
        while(idx <= n-1){
            if(nums[idx]-nums[idx-1] == 1){
                sum+=nums[idx];
            }else{
                break;
            }
            idx++;
        }
        unordered_set<int> st;
        cout << sum << endl;
        for(auto it: nums) st.insert(it);

        for(int i=sum; i<=1e9; i++){
            if(!st.count(i)) return i;
        }
        return -1;
    }
};