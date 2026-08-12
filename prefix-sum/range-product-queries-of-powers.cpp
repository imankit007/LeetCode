class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        constexpr long long kMod = 1e9 + 7;
        vector<int> powers;
        int pos = 0;
        while (n > 0) {
            int bit = n & 1;
            if (bit) {
                powers.push_back(1 << pos);
            }
            n = n >> 1;
            ++pos;
        }

        vector<int> ans;
        for (const vector<int>& query : queries) {
            int curr = 1;
            for (int i = query[0]; i <= query[1]; ++i) {
                curr = (1LL * curr * powers[i]) % kMod;
            }
            ans.push_back(curr);
        }

        return ans;
    }
};