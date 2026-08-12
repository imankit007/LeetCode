class Solution {
public:
    int smallestRepunitDivByK(int k) {

        if (k & 1 == 0 || k % 5 == 0) {
            return -1;
        }

        unordered_set<int> seen;
        int n = 0;
        for (int i = 1; i <= k; ++i) {
            n = (n * 10 + 1) % k;

            if (n == 0) {
                return i;
            }

            if (seen.contains(n)) {
                return -1;
            }

            seen.insert(n);
        }

        return -1;
    }
};