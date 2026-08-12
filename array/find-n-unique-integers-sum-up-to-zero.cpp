class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int i = 1;
        while (n > 1) {
            ans.push_back(i);
            ans.push_back(-1 * i);
            n -= 2;
            ++i;
        }

        if (n == 1) {
            ans.push_back(0);
        }
        return ans;
    }
};