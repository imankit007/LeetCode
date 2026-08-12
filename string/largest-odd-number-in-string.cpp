class Solution {
public:
    string largestOddNumber(string num) {
      const int size = num.size();
      const string vowel = "02468";
        for(int i=size-1; i>=0; i--){
                if(vowel.find(num[i])==string::npos){
                    return num.substr(0,i+1);
                }
        }

        return "";
    }
};