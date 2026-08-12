class Solution {
public:
    int myAtoi(string s) {
      long n = s.size();
       long long int temp = 0;
        bool isneg = false;
        int i = 0;
        
        while(s[i]==' '){
            i++;
        }
        
        if(s[i]=='-'){
            isneg =true;
            i++;
        }else if(s[i]=='+'){
            i++;
        }
        
            
        while(s[i]>='0' && s[i]<='9'){
            if(temp*10 > INT_MAX){
                if(!isneg)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            temp = (temp*10)+(long long int)(s[i]-'0');
            i++;
        }
        if(isneg){
            temp = -1 * temp;
        }
        
        
        if(temp<INT_MIN){
            return INT_MIN;
        }else if(temp > INT_MAX){
            return INT_MAX;
        }else{
            return (int)temp;
        }
    
    }
};