class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long ans = 0;

        long long curr = 0;

        for (int i = 0 ; i < nums.size(); ++i) {
            int num = nums[i];

            if (num == 0) {
                curr++;
            } 
            if(num!=0  || i == nums.size() - 1) {
                ans += (curr * (curr + 1)) / 2;
                curr = 0;
            }
        }

        return ans;
    }
};