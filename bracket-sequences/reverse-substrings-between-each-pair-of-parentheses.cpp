class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<char> st;

        for(const char c : s){
            if(c == ')'){
                string temp = "";
                while(!st.empty() && st.top() !='('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                for(const char c : temp){
                    st.push(c);
                }
            }else{
                st.push(c);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top(), st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }   
};