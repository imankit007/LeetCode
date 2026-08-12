class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        vector<int> count(26,0);
      
        for(const char& c:chars){
          count[c - 'a']++;
        }
        for(const string& word : words){
          bool flag = true;
          vector<int> temp(26,0);
            for(char c : word){
              temp[c-'a']++;
            }

          for(int i =0; i<26; i++){
            if(count[i]<temp[i])
              flag= false;
          }
          if(flag)
            ans+=word.length();
        }
        return ans;
    }
};