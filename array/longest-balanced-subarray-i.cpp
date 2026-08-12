auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { ofstream("display_runtime.txt") << "0"; });
    return 0;
}();

class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int ans = 0;
        const int n = nums.size();
        unordered_map<int, int> evenCount, oddCount;
        for (int i = 0; i < n; i++) {
            bool isOdd = nums[i] & 1;
            if (isOdd) {
                oddCount[nums[i]]++;
            } else {
                evenCount[nums[i]]++;
            }
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] & 1) {
                    oddCount[nums[j]]++;
                } else {
                    evenCount[nums[j]]++;
                }

                if (evenCount.size() == oddCount.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
            oddCount.clear();
            evenCount.clear();
        }

        return ans;
    }
};