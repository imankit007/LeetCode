class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        constexpr int kMod = 1e9 + 7;
        int ans = 0;
        const int n = nums.size();

        vector<long long> powerOfTwo(n + 1);

        powerOfTwo[0] = 1;

        for (int i = 1; i <= n; i++) {
            powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % kMod;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {

            if (nums[i] * 2ll > target) {
                continue;
            }

            int j = upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]) - nums.begin() - 1;

            ans = ( ans +  powerOfTwo[j-i] ) % kMod;

        }

        return ans;
    }
};