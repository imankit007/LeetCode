class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        const int m = grid.size();
        const int n = grid[0].size();

        constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int fresh = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
            }
        }

        if (fresh == 0)
            return 0;

        int step = 0;

        while (!q.empty()) {
            step++;
            for (int sz = q.size(); sz > 0; --sz) {
                pair<int, int> curr = q.front();
                q.pop();
                for (const auto& [dx, dy] : kDirs) {
                    const int x = curr.first + dx;
                    const int y = curr.second + dy;

                    if (x < 0 || x == m || y < 0 || y == n) {
                        continue;
                    }
                    if (grid[x][y] != 1)
                        continue;

                    grid[x][y] = 2;
                    q.emplace(x, y);
                    --fresh;
                }
            }
        }

        return fresh == 0 ? step - 1 : -1;
    }
};