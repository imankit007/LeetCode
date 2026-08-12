class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (const string s : logs) {
            const char c2 = s[s.length() - 2];
            if (c2 == '.') {
                if ( s.length() > 2 && s[s.length() - 3] == '.')
                    depth = depth==0? 0 : --depth;
            } else {
                ++depth;
            }
        }
        return depth;
    }
};