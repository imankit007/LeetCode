class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        const long long sum = accumulate(nums.begin(), nums.end(), 0ll);

        const int totalRem = sum % p;

        if (totalRem == 0) {
            return 0;
        }

        const int n = nums.size();
        unordered_map<int, int> lastIndexMap;
        lastIndexMap[0] = -1;
        int minLength = n;
        long long currPrefixRemainder = 0;

        for (int i = 0; i < nums.size(); ++i) {

            currPrefixRemainder = (currPrefixRemainder + nums[i]) % p;

            int targetRemainder =
                (currPrefixRemainder - totalRem + p) % p;

            if (lastIndexMap.count(targetRemainder)) {
                minLength = min(minLength, i - lastIndexMap[targetRemainder]);
            }

            lastIndexMap[currPrefixRemainder] = i;
        }

        return minLength == n ? -1 : minLength;
    }
};