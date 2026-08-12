class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        const int n  = nums.size();

        vector<int> ans(n);

        int totalSum = accumulate(nums.begin(), nums.end(),0);

        int leftSum = 0;


        for(int i = 0; i<n; i++){

            int leftCount = i;
            int rightCount = n - 1 - i;

            int rightSum = totalSum - leftSum - nums[i];

            int left = (leftCount * nums[i]) - leftSum;
            int right = rightSum - (rightCount * nums[i]);

            ans[i] = left +  right;

            leftSum+=nums[i];
        }

        return ans;


    }
};