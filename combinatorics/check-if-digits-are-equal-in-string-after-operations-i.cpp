class Solution {
public:
    bool hasSameDigits(string s) {

        while (s.size() > 2) {

            string str = "";

            for (int i = 1; i < s.size(); i++) {
                int a = s[i - 1] - '0';
                int b = s[i] - '0';

                int res = (a + b) % 10;

                str += res;
            }
            s = str;
        }

        return s[0] == s[1];
    }
};