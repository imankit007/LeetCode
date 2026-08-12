class Solution {
public:
    int numWaterBottles(int m, int n) {
        int ans = m;

        while(m >= n){
            ans+= (m / n);
            m =( m / n )+( m % n);
        }

        return ans;
    }
};