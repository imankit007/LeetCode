class Solution {
public:
    string addStrings(string num1, string num2) {
        int a= num1.size() -1 , b = num2.size() -1;
        int carry = 0;
        int res= 0;
        string ans;
        for(; a >= 0 || b >= 0||carry; carry = res /10){
            int c1 =0;
            int c2 = 0;
            if(a>=0){
                 c1 = num1[a--] - '0';
            }
            if(b >= 0){
                c2  = num2[b--] - '0';
            }
            
             res  = c1 + c2 + carry;
            
            ans += to_string(res % 10);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    
};