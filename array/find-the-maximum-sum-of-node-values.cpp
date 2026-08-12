class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        long long maxSum = 0;
        int count = 0;
        int minDiff = INT_MAX;

        for(const int &num : nums){
            maxSum += max(num, num^k);
            count+=((num^k )> num)? 1: 0;
            minDiff = min(minDiff, abs(num-( num^k)));
        }

        if(count%2==0)
            return maxSum;
        return maxSum-minDiff;
    }
};