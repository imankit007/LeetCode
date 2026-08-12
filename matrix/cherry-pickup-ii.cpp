class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        const int row = grid.size();
        const int col = grid[0].size();

        vector<vector<vector<int>>> dp(
            row, vector<vector<int>>(col, vector<int>(col, -1)));

        return solve(grid, 0, 0, col - 1, dp);
    }

private:
    int solve(const vector<vector<int>>& grid, int x, int y1, int y2,
               vector<vector<vector<int>>>& dp) {

        if (x == grid.size())
            return 0;
        if (y1 < 0 || y1 == grid[0].size() || y2 < 0 || y2 == grid[0].size())
            return 0;
        if (dp[x][y1][y2] != -1)
            return dp[x][y1][y2];

        const int numRow = grid[x][y1] + ((y1==y2) ? 0 : 1) * grid[x][y2];

        for (int d1 = -1; d1 <= 1; d1++){
            for(int d2 = -1; d2<=1; d2++){
                dp[x][y1][y2] = max(dp[x][y1][y2],numRow + solve(grid, x+1, y1+d1, y2+d2, dp));
            }
        }
            return dp[x][y1][y2];
    }
};