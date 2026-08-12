class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<bool> lower(26), upper(26);

        for (const char c : word)
            if (isupper(c))
                upper[c - 'A'] = true;
            else
                lower[c - 'a'] = !upper[c - 'a'];

        int ans = 0;

        for (int i = 0; i < 26; i++)
            if (lower[i] && upper[i])
                ++ans;

        return ans;
    }
};