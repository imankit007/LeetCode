class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        const int n = grid.size();
        const int m = grid[0].size();

        vector<int> arr;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        ranges::sort(arr);

        int mid = arr.size() / 2;

        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (abs(arr[i] - arr[mid] ) % x != 0) {
                return -1;
            }

            int rem = abs(arr[i] - arr[mid] );

            ans += (rem / x);
        }

        return ans;
    }
};