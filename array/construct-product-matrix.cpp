
#define ll long long

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        const int m = grid.size();
        const int n = grid[0].size();
        const int MOD = 12345;
        vector<vector<int>> ans(m, vector<int>(n, 1));

        ll prefix = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = prefix;
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }

        ll suffix = 1;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                ans[i][j] = (ans[i][j] * suffix) % MOD;
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }

        return ans;
    }
};