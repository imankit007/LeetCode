class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int n = nums.size();
        ranges::sort(nums);

        int ans = 0;

        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;

            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    ans += right - left;
                    right--;
                } else {
                    left++;
                }
            }
        }

        return ans;
    }
};