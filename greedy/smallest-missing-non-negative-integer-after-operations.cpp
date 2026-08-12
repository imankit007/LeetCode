class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        vector<int> freq(value, 0);

        for (const int& n : nums) {
            int r = n % value;
            if (r < 0)
                r += value;
            freq[r]++;
        }

        int m = 0;
        while (true) {
            int r = m % value;
            if (freq[r] == 0)
                return m;
            freq[r]--;
            m++;
        }
    }
};