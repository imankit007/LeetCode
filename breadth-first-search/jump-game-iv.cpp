class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int n = arr.size();

        unordered_map<int, vector<int>> mp;

        vector<int> visited(n, 0);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        int ans = 0;

        q.push(0);
        visited[0] = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int curr = q.front();
                q.pop();
                if (curr == n - 1) {
                    return ans;
                }

                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = 1;
                    q.push(curr - 1);
                }
                if (curr + 1 <= n - 1 && !visited[curr + 1]) {
                    visited[curr + 1] = 1;
                    q.push(curr + 1);
                }

                for (int d : mp[arr[curr]]) {
                    if (!visited[d]) {
                        visited[d] = 1;
                        q.push(d);
                    }
                }

                mp[arr[curr]].clear();
            }
            ans++;
        }

        return n - 1;
    }
};