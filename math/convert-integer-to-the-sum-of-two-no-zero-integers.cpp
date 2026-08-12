class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {

        for (int i = 1; i < n; ++i) {
            int first = i;
            int second = n - i;
            if (verify(first) && verify(second)) {
                return {first, second};
            }
        }

        return {0, 0};
    }

private:
    bool verify(int n) {
        while (n > 0) {
            int d = n % 10;
            if (d == 0) {
                return false;
            }
            n /= 10;
        }
        return true;
    }
};