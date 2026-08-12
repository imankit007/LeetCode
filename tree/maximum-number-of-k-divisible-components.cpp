class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<vector<int>> graph(n);
        int ans = 0;
        for(const vector<int> &edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        function<long long(int , int)> dfs = [&](int curr, int parent){
            long long subTreeSum = values[curr];

            for(int child : graph[curr]){
                if(child != parent){
                    subTreeSum += dfs(child, curr);
                }
            }
            if(subTreeSum % k == 0){
                ans++;
                return 0LL;
            }

            return subTreeSum;
        };

        dfs(0, -1);

        return ans;
    }
};