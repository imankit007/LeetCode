class Solution {
public:
    int countPalindromicSubsequence(string s) {

        vector<int> first(26, s.length());
        vector<int> last(26, -1);
        int ans = 0;

        vector<int> prefix(s.length(), 0);
        for (int i = 0; i < s.length(); ++i) {
            int index = s[i] - 'a';
            first[index] = min(first[index], i);
            last[index] = i;



        }

        for (int i = 0; i < 26; ++i) {

            if (first[i] < last[i]) {
                ans+= unordered_set<int>(s.begin() + first[i] + 1, s.begin() + last[i]).size();
            }
        }

        return ans;
    }
};