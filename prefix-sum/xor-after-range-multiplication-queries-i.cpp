class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        constexpr int kMod = 1e9 + 7;

        for (const vector<int>& query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];
            for (; l <= r; l = l + k) {
                nums[l] = (1ll * nums[l] * v) % kMod;
            }
        }

        return accumulate(nums.begin(), nums.end(), 0,
                          [](int acc, int num) { return acc ^ num; });
    }
};