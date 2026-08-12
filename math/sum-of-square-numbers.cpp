class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0;
        int r = sqrt(c);

        while (l <= r) {
            long long squareSum = (1L *l * l) + (r * r);
            if (c == squareSum)
                return true;
            if (c > squareSum)
                ++l;
            else
                --r;
        }

        return false;
    }
};