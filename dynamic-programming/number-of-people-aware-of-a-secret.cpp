class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {

        constexpr int kMod = 1e9 + 7;

        vector<int> dp(n);
        dp[0] = 1;
        long share = 0;
        for (int i = 1; i < n; i++) {
            if (i - delay >= 0) {
                share += dp[i - delay];
            }
            if (i - forget >= 0) {
                share -= dp[i - forget];
            }
            share += kMod;
            share %= kMod;
            dp[i] = share;
            
        }

        int ans = 0;
        for (int i = n - forget; i <n; ++i) {
            ans = (ans + dp[i]) % kMod;
        }
        return ans;
    }
};