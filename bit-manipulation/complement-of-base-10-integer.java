class Solution {
    public int bitwiseComplement(int n) {
        
        if(n==0){
            return 1;
            
        }
        
        int b = 1;
        
        while(n>=b){
            n= n^b;
            b = b<<1;
        }
        return n;
    }
}