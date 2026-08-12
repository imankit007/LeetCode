class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const int maxBitSize = 30;

        vector<int> ans(nums.size(),1);
        vector<int> result(maxBitSize);

        for(int i = nums.size() - 1; i >= 0 ; --i){
            for(int j = 0; j < maxBitSize; ++j){
                if(nums[i]>>j & 1){
                    result[j] = i;
                }
                ans[i] = max(ans[i], result[j] - i + 1);
            }
        }
        return ans;
    }
};