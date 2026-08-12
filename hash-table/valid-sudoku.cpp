class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        const int n = board.size();

        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '1';
                int boxNum = (i / 3) * 3 + (j / 3);

                if (rows[i][num] || cols[j][num] || boxes[boxNum][num]) {
                    return false;
                }

                rows[i][num] = cols[j][num] = boxes[boxNum][num] = true;
            }
        }
        return true;
    }
};