class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int lenS1 = word1.length();
        int lenS2 = word2.length();



        for(int i =0; i<lenS1 || i<lenS2; i++){
          if(i<lenS1)
            ans+=word1[i];
          if(i<lenS2)
            ans+=word2[i];
        } 

        

        return ans;

    }
};