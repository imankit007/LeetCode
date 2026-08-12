class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        long long ans = LLONG_MIN;

        vector<long long> prefixSum(k, 1e18);

        long long prefix = 0;
        prefixSum[k - 1] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];
            ans = max(ans, prefix - prefixSum[i % k]);
            prefixSum[i % k] = min(prefixSum[i % k],  prefix);
        }

        return ans;
    }
};