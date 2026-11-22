class Solution {
public:
    bool checkString(string s) {
        bool check = false;
        for(auto it : s){
            if(it == 'b') check = true;
            else{
                if(check) return false;
            }
        }
        return true;
    }
};