class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        const int n = grid.size();

        unordered_map<int, int> count;

        vector<int> ans(2);

        for (const vector<int> row : grid) {
            for (const int n : row) {
                if (count[n] == 1) {
                    ans[0] = n;
                }
                count[n]++;
            }
        }

        for (int i = 1; i <= n * n; ++i) {
            if (count[i] == 0) {
                ans[1] = i;
            }
        }

        return ans;
    }
};