class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        const int m = grid.size();
        const int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));


        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                const int curr = (i * n + j + k) % (m * n);

                const int x = curr / n;
                const int y = curr % n;

                ans[x][y] = grid[i][j]; 

            }
        }
        return ans;


    }
};