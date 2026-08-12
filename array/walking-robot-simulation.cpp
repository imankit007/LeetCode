class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        unordered_set<pair<int,int>, PairHash> obs;
        for (const vector<int>& obstacle : obstacles) {
            obs.emplace(obstacle[0], obstacle[1]);
        }

        int x = 0;
        int y = 0;

        int d = 0;
        int ans = 0;
        for (const int command : commands) {
            if (command == -1) {
                d = (d + 1) % 4;
            } else if (command == -2) {
                d = (d + 3) % 4;
            } else {
                for (int k = 0; k < command; k++) {
                    if (obs.contains({x + kDirs[d][0], y + kDirs[d][1]})) {
                        break;
                    }
                    x += kDirs[d][0];
                    y += kDirs[d][1];
                }
            }

            ans = max(ans, x * x + y * y);
        }
        return ans;
    }

private:
  struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };
};