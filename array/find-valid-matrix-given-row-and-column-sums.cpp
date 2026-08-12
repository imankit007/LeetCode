class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int row  = rowSum.size();
        const int col = colSum.size();

        vector<vector<int>> ans(row, vector<int>(col));

        for(int i =0; i<row; ++i){
            for(int j =0; j<col; ++j){
                int mini = min(rowSum[i], colSum[j]);
                ans[i][j] = mini;
                rowSum[i] = max(0, rowSum[i]-mini);
                colSum[j] = max(0, colSum[j]-mini);
            }
        }
        return ans;
    }
};