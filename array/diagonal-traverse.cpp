class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();

        vector<int> ans;
        vector<int> diagonal;

        for (int diag = 0; diag < m + n - 1; ++diag) {

            int i = diag < n ? 0 : diag - n + 1;
            int j = diag < n ? diag : n - 1;

            while (i < m && j >= 0)
                diagonal.push_back(mat[i++][j--]);

            if(diag % 2 == 0){
                    reverse(diagonal.begin(), diagonal.end());
            }

            ans.insert(ans.end(), diagonal.begin(), diagonal.end());
            diagonal.clear();
        }

        return ans;
    }
};