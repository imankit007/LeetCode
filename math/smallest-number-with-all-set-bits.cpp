class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0;

        while (n>0) {
            ans = (ans * 2) + (1);
            n = n >> 1;
        }
        return ans;
    }
};