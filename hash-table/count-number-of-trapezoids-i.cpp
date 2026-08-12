class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        constexpr int kMod = 1e9 + 7;
        map<int, long long> numOfPointOnY;

        for (const vector<int>& point : points) {
            numOfPointOnY[point[1]]++;
        }

        vector<long long> edges;

        for (const auto& it : numOfPointOnY) {
            const long long count = it.second;
            if (count >= 2) {
                edges.push_back(count * (count - 1) / 2);
            }
        }

        long long ans = 0;
        long long prefix = 0;

        for (const long long& edge : edges) {
            ans = (((edge * prefix) % kMod) + ans) % kMod;
            prefix += edge;
        }

        return ans;
    }
};