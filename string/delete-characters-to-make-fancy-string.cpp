class Solution {
public:
    string makeFancyString(string s) {

        string ans = "";

        for (int i = 0; i < s.length(); ++i) {
            if (ans.length() >= 2) {
                int curr = ans.length() -1;
                if ( s[i] == ans[curr] &&  ans[curr] == ans[curr - 1] ) {
                    continue;
                }
            }

            ans += s[i];
        }
        return ans;
    }
};