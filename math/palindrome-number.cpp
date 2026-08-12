class Solution {
public:
    bool isPalindrome(int x) {
        long temp = 0;
        int init = x;
        while(x > 0){
            temp = (temp*10) + (x%10);
            x = x/10;
        }
        
        if(temp==init)  
            return true;
        else
            return false;
        
    }
};