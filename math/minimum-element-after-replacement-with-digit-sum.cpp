class Solution {
public:
    int minElement(vector<int>& nums) {

        int ans = INT_MAX;

        for ( int n : nums) {
            int curr = 0;
            while (n) {
                curr += n % 10;
                n /= 10;
            }

            ans = min(ans, curr);
        }

        return ans;
    }
};