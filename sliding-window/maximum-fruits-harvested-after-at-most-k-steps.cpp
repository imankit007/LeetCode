class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0;
        int ans = 0;
        int curr = 0;

        for (int right = 0; right < fruits.size(); ++right) {

            int rightPos = fruits[right][0];
            int rightCount = fruits[right][1];
            curr += rightCount;

            while (left <= right) {
                int leftPos = fruits[left][0];

                int leftDistance = abs(startPos - leftPos);
                int rightDistance = abs(rightPos - startPos);
                int currDistance =
                    rightPos - leftPos + min(leftDistance, rightDistance);

                if (currDistance <= k) {
                    break;
                }

                curr -= fruits[left][1];
                left++;
            }

            ans = max(ans, curr);
        }
        return ans;
    }
};