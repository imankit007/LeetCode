class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {

        vector<int> res;
        vector<int> parent(c + 1, 0);
        vector<bool> is_online(c + 1, true);

        map<int, priority_queue<int, vector<int>, greater<int>>> group_heaps;

        for (int i = 1; i <= c; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < connections.size(); ++i) {
            unionset(connections[i][0], connections[i][1], parent);
        }

        for (int i = 1; i <= c; ++i) {
            int root = find(i, parent);
            group_heaps[root].push(i);
        }

        for (int i = 0; i < queries.size(); i++) {

            if (queries[i][0] == 2) {
                is_online[queries[i][1]] = false;
            } else {

                if (is_online[queries[i][1]] == true) {
                    res.push_back(queries[i][1]);
                } else {
                    int root = find(queries[i][1], parent);
                    auto& heap_r = group_heaps[root];
                    while (!heap_r.empty() &&
                           is_online[heap_r.top()] == false) {
                        heap_r.pop();
                    }
                    if (heap_r.empty()) {
                        res.push_back(-1);
                    } else {
                        res.push_back(heap_r.top());
                    }
                }
            }
        }

        return res;
    }

private:
    int find(int a, vector<int>& parent) {
        if (parent[a] == a) {
            return a;
        }

        return parent[a] = find(parent[a], parent);
    }

    void unionset(int a, int b, vector<int>& parent) {
        int parent_a = find(a, parent);
        int parent_b = find(b, parent);

        parent[parent_a] = parent_b;
    }
};