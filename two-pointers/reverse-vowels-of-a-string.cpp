class Solution {
public:

    bool isVowel(char c){
      return c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U';
    }

    string reverseVowels(string s) {
        
        stack<char> st;
        for(char c: s){  
            if(isVowel(c))
              st.push(c);
        }

        for(int i=0; i<s.length();i++){
          if(isVowel(s[i])){
            s[i]=st.top();
            st.pop();
          }
        }
        return s;
    }
};