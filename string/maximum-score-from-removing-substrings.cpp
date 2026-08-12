class Solution {
    public:
     int maximumGain(string s, int x, int y) {
       
       if(x>y){
        return helper1(s,x,y);
       }
        return helper2(s,x,y);
    }
    // to calcualte if x > y
    int helper1(string s, int x, int y){
         int ans = 0;
        vector<char> st;
        vector<char> st2;
        for(char c: s){
            if(c =='b' && !st.empty() && st.back() == 'a'){
                ans+=x;
                st.pop_back();
            }else{
                st.push_back(c);
            }
        }
         for(char c: st){
            if(c =='a' && !st2.empty() && st2.back() == 'b'){
                ans+=y;
                st2.pop_back();
            }else{
                st2.push_back(c);
            }
        }
        
        return ans;
    }
    int helper2(string s, int x, int y){
         int ans = 0;
        vector<char> st;
        vector<char> st2;
        for(char c: s){
            if(c =='a' && !st.empty() && st.back() == 'b'){
                ans+=y;
                st.pop_back();
            }else{
                st.push_back(c);
            }
        }
         for(char c: st){
            if(c =='b' && !st2.empty() && st2.back() == 'a'){
                ans+=x;
                st2.pop_back();
            }else{
                st2.push_back(c);
            }
        }
        
        return ans;
    }

};