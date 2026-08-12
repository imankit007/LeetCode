class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        vector<int> ans;
        ranges::sort(nums);

        int next = nums[0];
        for (const int n : nums) {

            while (next < n) {
                ans.push_back(next);
                ++next;
            }

            next = n + 1;
        }

        return ans;
    }
};