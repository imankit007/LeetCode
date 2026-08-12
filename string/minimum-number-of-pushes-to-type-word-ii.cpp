class Solution {
public:
    int minimumPushes(string word) {

        vector<int> freq(26, 0);

        for (const int& c : word) {
            freq[c - 'a']++;
        }

        ranges::sort(freq, greater<int>());

        int ans = 0;

        for (int i = 0; i < 26; i++){
            ans += freq[i] * ((i / 8) + 1   );
        }

        return ans;
    }
};