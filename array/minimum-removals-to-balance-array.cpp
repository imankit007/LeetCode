class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        const int n = nums.size();

        ranges::sort(nums);

        int maxValid = 0;

        for (int left = 0; left < n; left++) {
            int right = n;

            if(1LL * k * nums[left] <= nums[n-1]){
                right = upper_bound(nums.begin(), nums.end(), 1LL * k * nums[left]) - nums.begin();
            }
            maxValid = max(maxValid, right - left);
        }
        return n - maxValid;
    }
};