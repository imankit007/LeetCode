class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        const int m = grid.size();
        const int n = grid[0].size();

        int ans = 0;

        int minRow = INT_MAX;
        int maxRow = INT_MIN;
        int minCol = INT_MAX;
        int maxCol = INT_MIN;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        ans = (maxRow - minRow + 1) * (maxCol - minCol + 1);
        return ans;
    }
};