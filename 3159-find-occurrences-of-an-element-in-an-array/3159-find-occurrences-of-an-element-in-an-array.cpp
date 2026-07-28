class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int>mp; //occ,index
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == x){
                cnt++;
                mp[cnt]=i;
            }
        }
        vector<int> ans;
        for(auto it: queries){
            if(mp.count(it)){
                ans.push_back(mp[it]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};