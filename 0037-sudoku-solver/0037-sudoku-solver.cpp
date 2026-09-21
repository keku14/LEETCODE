class Solution {
public:
    void solveSudoku(vector<vector<char>>& mat) {
        fn(mat);
    }
    bool fn(vector<vector<char>>& mat){
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(mat[i][j] == '.'){
                    for(char k = '1';k<='9';k++){
                        if(poss(mat,i,j,k)){
                            mat[i][j] = k;
                            if(fn(mat)) return true;
                            else mat[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool poss(vector<vector<char>>& mat,int row,int col,char c){
        for(int i = 0;i<9;i++){

            if(mat[i][col] == c || mat[row][i] == c) return false;

            if(mat[3 * (row/3) + i/3][3 * (col/3) + i%3] == c) return false;
        }
        return true;
    }
};
