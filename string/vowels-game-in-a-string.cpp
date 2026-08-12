class Solution {
public:
    bool doesAliceWin(string s) {
       
        return ranges::any_of(s, [this](const char c){ return isVowel(c);});
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};