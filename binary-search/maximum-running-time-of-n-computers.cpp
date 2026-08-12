class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {

        long long left = 0;

        long long right = accumulate(batteries.begin(), batteries.end(), 0LL);

        while (left < right) {
            long long mid = left + (right - left + 1) / 2;

            long long total = 0;
            for (int battery : batteries) {
                total += min(static_cast<long long>(battery), mid);
            }

            if (total >= n * mid) {
                left = mid;
            } else {
                right = mid - 1;
            }
        } 
        return left;
    }
};