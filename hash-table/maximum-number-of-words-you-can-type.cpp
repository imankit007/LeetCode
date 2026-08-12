class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0 ;
        bool canType = true;
        for(const char c : text){
            if(c == ' ' ){
                if(canType){
                    ++ans;
                }
                canType = true;
            }else{
                if(brokenLetters.find(c) != string::npos){
                    canType = false;
                }
            }
        }
        return ans + canType;
    }
};