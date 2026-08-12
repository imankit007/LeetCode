class Solution {
public:
    int smallestNumber(int n, int t) {
        
        for(int i = n ; i < n + 10; i++){
            if(productOfDigit(i) % t == 0){
                return i;
            }
        }

        return n;

    }


private: 
    int productOfDigit(int n){
        int ans = 1;
        while(n){
            ans  *= n%10;
            n /= 10;
        }
        return ans;
    }    
};