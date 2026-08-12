class Solution {
public:
    int maxVowels(string s, int k) {
        const int n = s.size();
        int ans = 0;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            
            if(isVowel(s[i]))
                ++temp;
            if(i>=k && isVowel(s[i-k]))
                --temp;
            ans = max(ans, temp);
        }
        return ans;
    }

private:
    bool static isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};