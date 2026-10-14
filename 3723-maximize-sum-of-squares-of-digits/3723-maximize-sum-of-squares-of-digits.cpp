class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num)return "";
        string curr = "";
        int s = 0;
        while(curr.length() < num){
            for(int i = 9;i>=0;i--){
                s += i;
                if(s <= sum){
                    curr += to_string(i);
                    break;
                }else{
                    s -= i;
                }
            }
        }
        return curr;
    }
};