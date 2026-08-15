class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        const int n = nums.size();

        int curr = 0;
        bool zero = true;
        for (const int &n : nums) {
            if (n != 0) {
                zero = false;
            }
            curr ^= n;
        }

        if (zero) {
            return 0;
        }

        if (curr) {
            return n;
        }

        return n - 1;
    }
};