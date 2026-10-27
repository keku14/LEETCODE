// class Solution {
// public:
//     vector<string> createGrid(int m, int n) {
//         vector<string> v;
//         vector<vector<char>> ans(m,vector<char>(n,'#'));
//         int i = 0,j=0;
//         while(j+1 < n){
//             ans[i][j] = '.';
//             j++;
//         }
//         while(i < m){
//             ans[i][j] = '.';
//             i++;
//         }

//         for(int i = 0;i<m;i++){
//             string s = "";
//             for(int j = 0;j<n;j++){
//                 s += ans[i][j];
//             }
//             v.push_back(s);
//         }
//         return v;
//     }
// };
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m, string(n, '#'));
        for(int i = 0; i < m; i++){
            res[i][0] = '.';
        }

        for(int i = 0; i < n; i++){
            res[m - 1][i] = '.';
        }

        return res;
    }
};