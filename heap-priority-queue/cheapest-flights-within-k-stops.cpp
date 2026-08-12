class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> graph(n);

        for (const vector<int>& flight : flights) {
            const int s = flight[0];
            const int d = flight[1];
            const int p = flight[2];
            graph[s].emplace_back(d, p);
        }
        return solve(graph, src, dst, k);
    }

private:
    int solve(vector<vector<pair<int, int>>>& graph, int src, int dest, int k) {

        vector<vector<int>> dist(graph.size(), vector<int>(k + 2, INT_MAX));
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<>> minHeap;
        dist[src][k + 1] = 0;
        minHeap.emplace(dist[src][k + 1], src, k + 1);
        while (!minHeap.empty()) {
            const auto [price, city, stops] = minHeap.top();
            minHeap.pop();

            if (dest == city)
                return price;
            if (stops == 0)
                continue;

            for (const auto [v, w] : graph[city]) {
                if (price + w < dist[v][stops - 1]) {
                    dist[v][stops - 1] = price + w;
                    minHeap.emplace(dist[v][stops - 1], v, stops - 1);
                }
            }
        }
        return -1;
    }
};