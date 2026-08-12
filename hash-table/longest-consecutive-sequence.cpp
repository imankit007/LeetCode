class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;

        unordered_set<int> seen{nums.begin(), nums.end()};

        for (int n : seen) {

            if (seen.contains(n - 1)) {
                continue;
            }
            int length = 1;
            while (seen.contains(++n)) {
                ++length;
            }
            ans = max(ans, length);
        }
        return ans;
    }
};