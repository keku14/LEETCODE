class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> v(26,0);

        for(int i = 0;i<n;i++){
            v[word[i]-'a']++;
        }
        sort(v.rbegin(),v.rend());

        int ans = 0;
        for(int i = 0;i<26;i++){
            if(i>=0 && i<=7){
                ans += v[i];
            }
            if(i>7 && i<=15){
                ans += v[i]*2;
            }
            if(i>15 && i<=23){
                ans += v[i]*3;
            }
            if(i>23 && i<=25){
                ans += v[i]*4;
            }
        }
        return ans;
    }
};