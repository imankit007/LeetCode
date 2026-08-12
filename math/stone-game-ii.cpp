class Solution {
public:
    int stoneGameII(vector<int>& piles) {

        const int n = piles.size();
        vector<int> suffix = piles;
        // DP[i][M] returns the maximum number of stones a player can get based
        // on the turn states.
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = n - 2; i >= 0; --i) {
            suffix[i] += suffix[i + 1];
        }

        return solve(suffix, 0, 1, dp);
    }

private:
    int solve(vector<int>& suffix, int i, int M, vector<vector<int>>& dp) {

        // Base Case: Player can take all the remaining stones.
        if (i + 2 * M >= dp.size()) {
            return suffix[i];
        }

        // If already computed
        if (dp[i][M]) {
            return dp[i][M];
        }

        // Maximum number of stone opponent can take
        int opponent = suffix[i];

        // The number of stone opponent can pick optimally.
        for (int k = 1; k <= 2 * M; ++k) {
            opponent = min(opponent, solve(suffix, i + k, max(M, k), dp));
        }

        return dp[i][M] = suffix[i] - opponent;
    }
};