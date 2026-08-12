class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        for(int i= 0; i< board.size(); ++i){
            for(int j = 0; j<board[0].size(); ++j){
                if(solve(board, word, i, j, 0))
                    return true;
            }      
        }

     return false;
    }

    bool solve(vector<vector<char>>& board, string& word, int x, int y,
               int curr) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return false;
        if (board[x][y] != word[curr] || board[x][y] == '*')
            return false;
        if (curr == word.size()-1)
            return true;
        const char cache = board[x][y];
        board[x][y] = '*' ;

        const bool isExist = solve(board, word, x - 1, y, curr+1) ||
                             solve(board, word, x + 1, y, curr+1) ||
                             solve(board, word, x, y - 1, curr+1) ||
                             solve(board, word, x, y + 1, curr+1);
        board[x][y] = cache;
        return isExist;
    }
};