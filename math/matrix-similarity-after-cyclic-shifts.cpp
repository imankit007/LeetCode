class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        const int m = mat.size();
        const int n = mat[0].size();

        k = k % n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                int nJ = (j + k) % n;
                if (mat[i][j] != mat[i][nJ])
                    return false;
            }
        }
        return true;
    }
};