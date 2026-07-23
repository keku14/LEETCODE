class Solution {
public:
    int countPoints(string rings) {
        unordered_map<char,unordered_set<char>>mp;
        for(int i=0; i<rings.size(); i++){
            if(rings[i]=='B' || rings[i]=='G' || rings[i]=='R'){
                continue;
            }else{
                mp[rings[i]].insert(rings[i-1]);
            }
        }
        int cnt=0;
        for(auto it: mp){
            if(it.second.size() == 3) cnt++;
        }
        return cnt;
    }
};