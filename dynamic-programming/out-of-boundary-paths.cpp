class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(
            maxMove + 1, vector<vector<int>>(m, vector<int>(n, -1)));

        return solve(m ,n, maxMove, startRow, startColumn, dp);
    }

private:
  static constexpr int kMod = 1e9+7; 
    int solve(int m, int n, int maxMove, int startRow, int startColumn,
              vector<vector<vector<int>>>& dp) {
        if (isOutside(startRow, startColumn, m, n))
            return 1;

        if (maxMove == 0)
            return 0;

        if (dp[maxMove][startRow][startColumn] != -1)
            return dp[maxMove][startRow][startColumn];

     
        return dp[maxMove][startRow][startColumn] = ( solve(m, n, maxMove - 1, startRow - 1, startColumn, dp) * 1LL + 
       solve(m, n, maxMove - 1, startRow + 1, startColumn, dp)+
        solve(m, n, maxMove - 1, startRow, startColumn - 1, dp)+
      solve(m, n, maxMove - 1, startRow, startColumn + 1, dp))%kMod;
    }

    bool isOutside(int x, int y, int m, int n) {
        return x < 0 || x >= m || y < 0 || y >= n;
    }
};