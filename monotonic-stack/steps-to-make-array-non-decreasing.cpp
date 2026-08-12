class Solution {
public:
    int totalSteps(vector<int>& nums) {

        const int n = nums.size();

        vector<int> dp(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            int step = 1;
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                step = max(step, dp[s.top()] + 1);
                s.pop();
            }
            if(!s.empty())
                dp[i]= step;
            s.push(i);
        }

        return ranges::max(dp);
    }
};