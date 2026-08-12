class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        vector<int> dp(3);

        for (const int& num : nums) {
            // We initialze a new vetor because after 1st iteration of inner loop the vector changes and , we want the dp[] to  contain the values from previous iteration of outer loop. 
            for (const int sum : vector<int>(dp)) {
                dp[(sum + num) % 3] = max(dp[(sum + num) % 3], sum + num);
            }
        }
        return dp[0];
    }
};