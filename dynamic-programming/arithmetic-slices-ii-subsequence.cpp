class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));

        unordered_map<long, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                const long target = nums[j] * 2L - nums[i];
                if (const auto it = mp.find(target); it != mp.cend()) {
                    for (const int k : it->second) {
                        if (k < j) {
                            dp[i][j] += (dp[j][k] + 1);
                        }
                    }
                   
                }
                 ans += dp[i][j];
            }
        }

        return ans;
    }
};