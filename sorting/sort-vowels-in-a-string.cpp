class Solution {
public:
    string sortVowels(string s) {
        vector<char> bucket;


        for(const char c: s){
            if(isVowel(c)){
                bucket.push_back(c);
            }
        }

        ranges::sort(bucket.begin(), bucket.end());

        string ans = "";
        int i = 0;
        for(const char c : s){
            if(isVowel(c)){
                ans+= bucket[i++];
            }else{
                ans+=c;
            }
        }
        return ans;
    }

    bool isVowel(char c){
        c = tolower(static_cast<unsigned char>(c));
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u' ;
    }
};