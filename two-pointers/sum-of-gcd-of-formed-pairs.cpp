class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        const int n = nums.size();

        vector<int> prefixGcd(n);

        int curr = 0;

        for (int i = 0; i < n; i++) {
            curr = max(nums[i], curr);
            prefixGcd[i] = gcd(curr, nums[i]);
        }

        ranges::sort(prefixGcd);

        long long ans = 0;

        for (int i = 0; i < n / 2; i++) {
            ans += gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
        }

        return ans;
    }
};