class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        constexpr int kMod = 1e9 + 7;

        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                for (int sum = 0; sum < k; ++sum) {
                    const int newSum = (grid[i][j] + sum) % k;
                    if (i > 0) {
                        dp[i][j][newSum] += dp[i - 1][j][sum];
                    }
                    if (j > 0) {
                        dp[i][j][newSum] += dp[i][j - 1][sum];
                    }
                    dp[i][j][newSum] %= kMod;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};