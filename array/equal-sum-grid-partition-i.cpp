class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        const int m = grid.size();
        const int n = grid[0].size();

        using ll = long long;

        ll total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                total += grid[i][j];
            }
        }

        if (total & 1)
            return false;

        ll target = total / 2;

        ll curr = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                curr += grid[i][j];
            }
            if (curr == target)
                return true;
        }
        curr = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; ++i) {
                curr += grid[i][j];
            }

            if (curr == target)
                return true;
        }

        return false;
    }
};