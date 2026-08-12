class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        return solve(events, 0, k, dp);
    }

private:
    int solve(vector<vector<int>>& events, int curr, int k,
              vector<vector<int>>& dp) {

        if (k == 0 || curr == events.size()) {
            return 0;
        }

        if (dp[curr][k] != -1) {
            return dp[curr][k];
        }

        const auto it = upper_bound(
            events.begin() + curr, events.end(), events[curr][1],
            []( const int a, const vector<int> &b) { return b[0] > a; });

        const int dis = distance(events.begin(), it);

        return dp[curr][k] =
                   max(events[curr][2] + solve(events, dis, k - 1, dp),
                       solve(events, curr + 1, k, dp));
    }
};