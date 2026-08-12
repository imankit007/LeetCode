class Solution {
public:
    bool halvesAreAlike(string s) {

        const int n = s.size() /2;

        int vowelCount = 0;

        for(int i =0 ;i<n; i++){
            if(isVowel(s[i])) vowelCount++;
            if(isVowel(s[i+(n)])) vowelCount--;
        }   
        
        return vowelCount==0? true : false;


    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};