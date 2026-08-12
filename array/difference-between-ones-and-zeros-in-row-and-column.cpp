class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));


        const int numRows = grid.size();
        const int numCols = grid[0].size();

        vector<int> onesRow(numRows);
        vector<int> onesCol(numCols); 

        for(int i =0; i<numRows; i++){
            for(int j=0; j<numCols; j++){
                onesRow[i]+=grid[i][j];
                onesCol[j]+=grid[i][j];
            }
        }

        for(int i = 0;i<numRows; i++){
            for(int j = 0; j<numCols; j++){
                ans[i][j] = onesRow[i]+onesCol[j]-(numCols-onesRow[i])-(numRows-onesCol[j]);
            }
        }


        return ans;
    }
};