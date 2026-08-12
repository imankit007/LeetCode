class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor ==-1)
            return INT_MAX;
        
        const int sign = dividend>0 ^ divisor>0 ? -1 : 1;
        long ans = 0;
       long dvd = labs(dividend);
       long dvs = labs(divisor);

        while(dvd>=dvs){
            int i =0;
            while(dvd > (dvs<< (i+1))){
                i++;
            }
            ans+= (1<<i);
            dvd = dvd - (dvs<<i);
        }
        return ans * sign;
    }
};