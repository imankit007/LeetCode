class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {

        long long ans = 0;

        for (const vector<int>& query : queries) {

            int l = query[0];
            int r = query[1];

            ans += (getOperations(r) - getOperations(l - 1) + 1) / 2;
        }
        return ans;
    }

private:
    long getOperations(int n) {
        long ans = 0;
        int count = 0;

        for (int i = 1; i <= n; i *= 4) {
            const int l = i;
            const int r = min(n, i * 4 - 1);
            ans += static_cast<long>(r - l + 1) * ++count;
        }
        return ans;
    }
};