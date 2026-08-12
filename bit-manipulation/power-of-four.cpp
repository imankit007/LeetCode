class Solution {
public:
    bool isPowerOfFour(int n) {
            unsigned int x = n;
            return x > 0 && popcount(x) == 1 && (x - 1) % 3 == 0;
    }
};