class Solution {
public:
    int nextBeautifulNumber(int n) {
        
        while(!isBalanced(++n));
        return n;
    }

private:
    bool isBalanced(int n) {
        vector<int> count(10, 0);
        while (n > 0) {
            if (n % 10 == 0)
                return false;
            count[n % 10]++;
            n = n / 10;
        }

        for (int i = 1; i < 10; ++i) {
            if (count[i] > 0 && i != count[i])
                return false;
        }

        return true;
    }
};