class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int m = nums.size();

        vector<long long> leftSum(m, LLONG_MAX), rightSum(m, LLONG_MAX);
        // maxHeap for left side prefix SUM
        priority_queue<int> leftHeap;
        long long leftRunning = 0;

        for (int i = 0; i < m; i++) {
            leftRunning += nums[i];
            leftHeap.push(nums[i]);
            if (leftHeap.size() > n) {
                leftRunning -= leftHeap.top();
                leftHeap.pop();
            }
            if (leftHeap.size() == n) {
                leftSum[i] = leftRunning;
            }
        }
        // minHeap for right side prefix SUM
        priority_queue<int, vector<int>, greater<int>> rightHeap;
        long long rightRunning = 0;

        for (int i = m - 1; i >= 0; i--) {
            rightRunning += nums[i];
            rightHeap.push(nums[i]);
            if (rightHeap.size() > n) {
                rightRunning -= rightHeap.top();
                rightHeap.pop();
            }
            if (rightHeap.size() == n) {
                rightSum[i] = rightRunning;
            }
        }

        //leftSum[i] denotes the minimum sum of n elements from 0 to n
        //rightSum[i] denots the maxumum sum of n element  from n to 3*n - 1
        //In each iteration we only we consider the diference of rightSum - leftSum 
        
        long long ans = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; i++) {
            ans = min(ans, leftSum[i] - rightSum[i + 1]);
        }

        return ans;
    }
};