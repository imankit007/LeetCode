class Solution {
public:
    int numberOfWays(string corridor) {
        long ans =1;
        constexpr int kmod = 1e9+7; 
        int count = 0;
        int prev = -1;
        for(int i =0; i<corridor.length();i++){
          if(corridor[i]=='S'){
            if(++count>2 && count & 1){
              ans = (ans * (i-prev))%kmod;
            }
            prev=i;
          }
        }
return count>1 && count%2==0?ans:0;
    }

        
};