class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {

        const int m = grid.size();
        const int n = grid[0].size();

        for (int i = x; i < x + k /2 ;i++ ) {
            int revRow = x + k - 1 - (i - x );
            for (int j = y; j < y+k ; j++) {
                swap(grid[i][j], grid[revRow][j]);
            }
        }

        return grid;
    }
};