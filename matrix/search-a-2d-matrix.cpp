class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        const int m = matrix.size();
        const int n = matrix[0].size();

        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) {
            return false;
        }

        for (int i = 0; i < m; i++) {
            if (target > matrix[i][n - 1]) {
                continue;
            }

            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};