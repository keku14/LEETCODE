class Solution {
private:
    int fn(int row, vector<int>&res){
        int cnt=0;
        unordered_set<int> temp;
        for(auto it: res){
            temp.insert(it);
        }
        if(!temp.count(1) && !temp.count(2) && !temp.count(3) && !temp.count(4)){
            temp.insert(1);
           temp.insert(2);temp.insert(3);temp.insert(4);
            cnt++;
        }
        if(!temp.count(3) && !temp.count(4) && !temp.count(5) && !temp.count(6)){
           temp.insert(3);
           temp.insert(4);temp.insert(5);temp.insert(6);
            cnt++;
        }
        if(!temp.count(5) && !temp.count(6) && !temp.count(7) && !temp.count(8)){
           temp.insert(7);
           temp.insert(8);temp.insert(5);temp.insert(6);
            cnt++;
        }
        return cnt;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> mp; //reserved {row,cols of that row}
        for(auto it: reservedSeats){
            int row=it[0]-1;
            int col=it[1]-1;
            mp[row].push_back(col);
        }
        int ans=0;
        //row from 0 to n-1
        for(auto it: mp){
           ans+=fn(it.first,it.second);
        }
        ans += (n - mp.size()) * 2;
        return ans;
    }
};