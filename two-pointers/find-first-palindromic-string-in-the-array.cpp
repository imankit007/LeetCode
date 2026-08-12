class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(const string word : words)
            if(isPalindrome(word))
                return word;

        return "";

    }

    private: 
        bool isPalindrome(string word){
            string old = word;
            reverse(word.begin(), word.end());
            return old == word;
        }
};