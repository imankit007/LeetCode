class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        const int n = matrix.size();

        for(int row = n-2; row>=0; row--){
            for(int col = 0; col<n ; col++){

                int best = matrix[row+1][col];

                if(col>0){
                    best = min(best, matrix[row+1][col-1]);
                }
                if(col<n-1){
                    best = min(best, matrix[row+1][col+1]);
                }

                matrix[row][col] += best;
            }
        }

        for(int col =0; col<n; col++){
            ans= min(ans, matrix[0][col]);
        }

    return ans;

    }
};