class Solution {

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int m = heightMap.size();
        const int n = heightMap[0].size();
        if (m <= 1 || n <= 1) {
            return 0;
        }

        using HeightPosition = tuple<int, int, int>;
        vector<vector<bool>> visited(m, vector<bool>(n));
        priority_queue<HeightPosition, vector<HeightPosition>,
                       greater<HeightPosition>>
            minHeap;
        int ans = 0;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (row == 0 || row == m - 1 || col == 0 ||
                    col == n - 1) {
                    minHeap.emplace(heightMap[row][col], row, col);
                    visited[row][col] = true;
                }
            }
        }

        int directions[5] = {-1, 0, 1, 0, -1};

        while (!minHeap.empty()) {

            auto [currH, currR, currC] = minHeap.top();
            minHeap.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int nextRow = currR + directions[dir];
                int nextCol = currC + directions[dir + 1];

                if (nextRow >= 0 && nextRow < m && nextCol >= 0 &&
                    nextCol < n && !visited[nextRow][nextCol]) {

                    ans += max(0, currH - heightMap[nextRow][nextCol]);
                        visited[nextRow][nextCol] = true;

                    minHeap.emplace(
                        max(heightMap[nextRow][nextCol], currH),
                        nextRow, nextCol);
                }
            }
        }

        return ans;
    }
};