class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26);

        const int n = words.size();

        for (const string word : words) {
            for (const char c : word) {
                freq[c - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] % n != 0)
                return false;
        }
        return true;
    }
};