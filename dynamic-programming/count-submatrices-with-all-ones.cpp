class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {

        const int m = mat.size();
        const int n = mat[0].size();

        vector<vector<int>> nums(m, vector<int>(n));

        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    nums[i][j] = mat[i][j];
                } else if (mat[i][j] == 1) {
                    nums[i][j] = nums[i][j - 1] + 1;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = INT_MAX;
                for (int k = i; k >= 0; --k) {
                    x = min(x, nums[k][j]);
                    ans += x;
                }
            }
        }

        return ans;
    }
};