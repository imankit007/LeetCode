class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        string ans;
        string word ="";
        for(char c : s){
          if(c!=' '){
            word+=c;
          }else{
            if(!word.empty())
              st.push(word);
            word.clear();
          }
        }
        if(!word.empty())
          st.push(word);

        while(st.size()!=1){
          ans+=st.top()+" ";
          st.pop();
        }
        ans+=st.top();
  return ans;
    }
};