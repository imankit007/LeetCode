class Solution {
public:
    int maxFreqSum(string s) {

        vector<int> freq(26);

        for (const char c : s) {
            freq[c - 'a']++;
        }
        int maxV = 0;
        int maxC = 0;
        for(char c = 'a'; c <= 'z'; ++c ){
            if(isVowel(c)){
                maxV = max(maxV, freq[c - 'a']);
            }else{
                maxC = max(maxC, freq[c - 'a']);
            }
        }

        return maxV + maxC;
    }

private:
    bool isVowel(char ch) {
        ch = std::tolower(ch); // convert to lowercase to handle both cases
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};