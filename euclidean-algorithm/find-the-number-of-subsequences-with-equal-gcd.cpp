class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {

        const int maxNum = ranges::max(nums);

        vector<vector<vector<int>>> mem(
            nums.size(),
            vector<vector<int>>(maxNum + 1, vector<int>(maxNum + 1, 0)));
        return solve(nums, 0, 0, 0, mem);
    }

private:
    static constexpr int kMod = 1e9 + 7;

    int solve(const vector<int>& nums, int i, int x, int y,
              vector<vector<vector<int>>>& mem) {

        if (i == nums.size()) {
            return x > 0 && x == y;
        }
        if (mem[i][x][y] != 0) {
            return mem[i][x][y];
        }

        const int skip = solve(nums, i + 1, x, y, mem);

        const int s1 = solve(nums, i + 1, gcd(x, nums[i]), y, mem);

        const int s2 = solve(nums, i + 1, x, gcd(y, nums[i]), mem);

        return mem[i][x][y] = (static_cast<long long>(skip) + s1 + s2) % kMod;
    }
};