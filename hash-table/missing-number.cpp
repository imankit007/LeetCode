class Solution {
public:
    int missingNumber(vector<int>& nums) {

        const int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0 );

        int validSum = (n  * (n + 1)) / 2;

        return validSum - sum;
    }
};