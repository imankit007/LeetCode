class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int ans = 0;

        unordered_map<int, int> freq;

        int l = 0;

        for (int r = 0; r < nums.size(); ++r) {
            int curr = nums[r];
            if (++freq[curr] > k) {
                while (l < r && freq[curr] > k) {
                    --freq[nums[l++]];
                }
               
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};