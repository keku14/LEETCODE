class Solution {
public:
    bool fn(string a, string b){
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto it : nums){
            v.push_back(to_string(it));
        }
        
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n-i-1;j++){
                if(fn(v[j+1],v[j])){
                    swap(v[j+1],v[j]);
                }
            }
        }
        if(v[0] == "0") return "0";

        string ans = "";
        for(auto it : v){
            ans += it;
        }
        return ans;
    }
};