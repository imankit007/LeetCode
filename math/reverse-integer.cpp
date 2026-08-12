class Solution {
public:
    int reverse(int x) {
        bool negative =false;
        long reverse =0;
        long temp = x;
        if(temp<0){
            negative=true;
            temp= -1*temp;
        }//if
        
        
        while(temp > 0){
            reverse = (reverse* 10) + (temp % 10);
            temp = temp/10;
        }
        
        if(reverse > INT_MAX){
            return 0;
        }
        
        if(negative){
            return (int)(reverse * -1);
        }else{
            return (int)reverse;
        }
    }
};