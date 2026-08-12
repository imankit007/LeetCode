class Solution {
public:
    int numberOfSpecialChars(string word) {
         vector<int> lower(26, 0), upper(26, 0);

        for (char c : word) {
            if (islower(c))
                lower[c - 'a'] = 1;
            else
                upper[c - 'A'] = 1;
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i])
                ans++;
        }

        return ans;
    }
};