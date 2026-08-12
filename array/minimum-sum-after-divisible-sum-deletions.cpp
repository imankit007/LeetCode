class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {

        vector<long long> dp(k+1,LLONG_MAX );

        long long prefix_sum = 0;
        long long rem = 0;
        dp[0] = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            rem = prefix_sum % k;

            prefix_sum = min(prefix_sum, dp[rem]);
            dp[rem] = min(prefix_sum, dp[rem]);
        }
        return prefix_sum;
    }
};