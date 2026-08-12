class Solution {
public:
    int numSub(string s) {

        int ans = 0;

        constexpr int kMod = 1e9 + 7;
        int curr = -1;
        for (int i = 0; i < s.length(); ++i) {
            if(s[i] == '0')
                curr = i;
            ans=( ans + i - curr ) % kMod;
         
        }

        return ans % kMod;
    }
};
