// class Solution {
// public:
//     bool fn(int i){
//         int prev = -1;
//         while(i > 0){
//             int digi = i%10;
//             if(prev == -1){
//                 prev = digi;
//             }else{
//                 if(prev - digi != 1) return false;

//                 prev = digi;
//             }
//             i/=10;
//         }
//         return true;
//     }
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int> ans;
//         for(int i = low;i<=high;i++){
//             if(fn(i)) ans.push_back(i);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = 1; i <= 9; ++i) {
            int num = i;
            for (int j = i + 1; j <= 9; ++j) {
                num = num * 10 + j;
                if (num >= low && num <= high)
                    res.push_back(num);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};