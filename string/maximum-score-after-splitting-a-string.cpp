class Solution {
public:
    int maxScore(string s) {
        int onesum = 0;
        
        for(char c : s){
            if(c == '1')
                ++onesum;
        }
       
        int curr = 0;
        int ans = 0;

        for(int i =0 ; i<s.length()-1; ++i){
           char c = s[i];
            if(c == '0'){
                ++curr;
            }
            else{
                --onesum;
            }
             ans = max(ans, curr + onesum);
            
        }
   
        return ans;

    }
};