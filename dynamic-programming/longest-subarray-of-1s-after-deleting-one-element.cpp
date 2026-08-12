class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int ans = 0;
        int zeros = 0;

        for (int i = 0, j = 0; j < nums.size(); ++j) {
            if (nums[j] == 0)
                zeros++;

            while (zeros == 2)
                if (nums[i++] == 0)
                    zeros--;

            ans = max(ans, j - i);
        }

        return ans;
    }
};