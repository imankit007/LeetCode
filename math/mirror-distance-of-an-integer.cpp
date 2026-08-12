class Solution {
public:
    int mirrorDistance(int n) {


        return abs(n - reverse(n));

    }

private:
    int reverse(int n) {
        int rev = 0;
        while (n) {
            int d = n % 10;
            rev = (rev * 10) + d;
            n /= 10;
        }
        return rev;
    }
};