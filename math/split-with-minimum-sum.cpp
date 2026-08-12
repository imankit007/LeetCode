class Solution {
public:
    int splitNum(int num) {

        vector<int> digit;

        while (num > 0) {
            digit.push_back(num % 10);
            num /= 10;
        }
        ranges::sort(digit);
        vector<int> ans(2, 0);

        for (int i = 0, idx = 0; i < digit.size(); i++, idx = (idx + 1) % 2) {
            ans[idx] = (ans[idx] * 10) + digit[i];
        }

        return ans[0] + ans[1];
    }
};