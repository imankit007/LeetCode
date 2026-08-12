class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();

        vector < vector<int>> diag(2 * n + 1);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                diag[j - i + n].push_back(grid[i][j]);

        for (int i = 0; i < 2 * n + 1; ++i) {
            if (i <= n) {
                sort(diag[i].begin(), diag[i].end());
            } else {
                sort(diag[i].rbegin(), diag[i].rend());
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                grid[i][j] = diag[j - i + n].back(), diag[j - i + n].pop_back();

        return grid;
    }
};