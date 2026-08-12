class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int m = heights.size();
        const int n = heights[0].size();
        vector<vector<int>> ans;
        queue<pair<int, int>> qP;
        queue<pair<int, int>> qA;
        vector<vector<bool>> seenP(m, vector<bool>(n));
        vector<vector<bool>> seenA(m, vector<bool>(n));

        int dirs[5] = {-1, 0, 1, 0, -1};

        auto bfs =
            [&](queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
                while (!q.empty()) {
                    auto [i, j] = q.front();
                    q.pop();
                    const int h = heights[i][j];
                    for (int d = 0; d < 4; d++) {
                        const int x = i + dirs[d];
                        const int y = j + dirs[d + 1];

                        if (x < 0 || x == m || y < 0 || y == n) {
                            continue;
                        }

                        if(visited[x][y] || heights[x][y] < h){
                            continue;
                        }
                        q.emplace(x, y);
                        visited[x][y] = true;
                    }
                }
            };

        for(int i =0 ; i < m ; i++){
            qP.emplace(i, 0);
            qA.emplace(i, n - 1);
            seenP[i][0] = true;
            seenA[i][n-1] = true;
        }

        for(int j = 0 ; j< n ; j++){
            qP.emplace(0,j);
            qA.emplace(m-1,j);
            seenP[0][j] = true;
            seenA[m-1][j] = true;
        }

        bfs(qP, seenP);
        bfs(qA, seenA);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(seenP[i][j] && seenA[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};