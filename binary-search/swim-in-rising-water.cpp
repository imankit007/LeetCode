class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        int ans = grid[0][0];
        int dir[5] = {-1, 0, 1, 0, -1};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            minHeap;

        vector<vector<bool>> seen(n, vector<bool>(n));

        minHeap.emplace(grid[0][0], 0, 0);
        seen[0][0] = true;

        while (!minHeap.empty()) {
            auto [height, currX, currY] = minHeap.top();
            minHeap.pop();
            ans = max(ans, height);
            if (currX == n - 1 && currY == n - 1)
                return ans;
            for (int i = 0; i < 4; i++) {
                int nX = currX + dir[i];
                int nY = currY + dir[i + 1];
                if (nX < 0 || nX == n || nY < 0 || nY == n)
                    continue;
                if (seen[nX][nY])
                    continue;
                minHeap.emplace(grid[nX][nY], nX, nY);
                seen[nX][nY] = true;
            }
        }
        return ans;
    }
};