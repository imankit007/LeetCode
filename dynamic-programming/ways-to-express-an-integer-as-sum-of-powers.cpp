class Solution {
public:
    int numberOfWays(int n, int x) {
        constexpr long long kMod = 1e9+7;

        vector<vector<int>> dp(n+1, vector<int>(n +1, 0));

        dp[0][0] = 1;
        for(int i =1; i<=n ; ++i){
            long long currpow = pow(i,x);
            for(int j = 0; j <= n; ++j){
                dp[i][j] = dp[i-1][j];
                if(currpow <= j){
                    dp[i][j] = (dp[i][j] + dp[i-1][j-currpow] ) % kMod;
                }
            }
        }
        return dp[n][n];

    }
};