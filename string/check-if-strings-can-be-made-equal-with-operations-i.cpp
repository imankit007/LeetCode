class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        const int n = s1.size();

        vector<vector<int>> freq(2, vector<int>(26, 0));

        for (int i = 0; i < n; ++i) {
            ++freq[i & 1][s1[i] - 'a'];
            --freq[i & 1][s2[i] - 'a'];
        }

        for (int i = 0; i < 26; i++) {
            if (freq[0][i] != 0 || freq[1][i] != 0) {
                return false;
            }
        }

        return true;
    }
};