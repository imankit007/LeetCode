class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { solver(board, 0); }

private:
    bool solver(vector<vector<char>>& board, int s) {
        if (s == 81) {
            return true;
        }

        int x = s / 9;
        int y = s % 9;

        if (board[x][y] != '.')
            return solver(board, s + 1);

        for (char i = '1'; i <= '9'; ++i) {
            if (isValid(board, x, y, i)) {
                board[x][y] = i;
                if (solver(board, s + 1)) {
                    return true;
                }
                board[x][y] = '.';
            }
        }
        return false;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char val) {

        for (int i = 0; i < 9; ++i) {
            if (i != col && board[row][i] == val) {
                return false;
            }
        }

        for (int i = 0; i < 9; ++i) {
            if (i != row && board[i][col] == val) {
                return false;
            }
        }

        int x = 3 * (row / 3);
        int y = 3 * (col / 3);

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (row != x + i && col != y + j &&
                    board[x + i][y + j] == val) {
                    return false;
                }
            }
        }

        return true;
    }
};