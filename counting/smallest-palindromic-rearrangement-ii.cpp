class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int m = n / 2;

        vector<int> freq(26);
        for (int i = 0; i < m; i++)
            freq[s[i] - 'a']++;

        auto countWays = [&](const vector<int>& f) -> long long {
            long long ways = 1;
            int rem = 0;

            for (int x : f)
                rem += x;

            int left = rem;

            for (int cnt : f) {
                if (cnt == 0)
                    continue;

                ways *= comb(left, cnt, k );

                if(ways > k){
                    ways = k;
                }

                left -= cnt;
            }

            return ways;
        };

        if (countWays(freq) < k)
            return "";

        string leftHalf;

        for (int pos = 0; pos < m; pos++) {

            for (int c = 0; c < 26; c++) {

                if (freq[c] == 0)
                    continue;

                freq[c]--;

                long long ways = countWays(freq);

                if (ways >= k) {
                    leftHalf.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                freq[c]++;
            }
        }

        string right = leftHalf;
        reverse(right.begin(), right.end());

        if (n & 1)
            return leftHalf + string(1, s[m]) + right;

        return leftHalf + right;
    }

    long long comb(int n, int r, long long limit) {
    if (r > n) return 0;
    r = min(r, n - r);

    long long ans = 1;

    for (int i = 1; i <= r; i++) {
        ans = ans * (n - r + i);

        if (ans > limit * i)
            return limit;

        ans /= i;
    }

    return min(ans, limit);
}
};