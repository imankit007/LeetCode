class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        constexpr int kMod = 1e9+7;
        
        int m = target/2;

        if(n<=m){
            return (1LL* n *(n+1))/2 %kMod;
        }

        long long a  = (1LL + m)*m/2 %kMod;
        long long b = (1LL * target + target + n - m -1)* (n-m)/2 % kMod;

        return (a + b)%kMod; 
        
    }
};