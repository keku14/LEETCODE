class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        int m = board.size();
        int n = board[0].size();

        if (board[i][j] != word[idx])
            return false;

        // Entire word matched
        if (idx == word.size() - 1)
            return true;

        char temp = board[i][j];
        board[i][j] = '#';

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                board[ni][nj] == word[idx + 1]) {

                if (dfs(board, word, ni, nj, idx + 1)) {
                    //board[i][j] = temp;
                    return true;
                }
            }
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] &&
                    dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};