class UnionFind {
public:
    UnionFind(int n) : id(n), rank(n) { iota(id.begin(), id.end(), 0); }

    void unionByRank(int u, int v) {
        const int i = find(u);
        const int j = find(v);
        if (i == j)
            return;
        if (rank[i] < rank[j]) {
            id[i] = j;
        } else if (rank[i] > rank[j]) {
            id[j] = i;
        } else {
            id[i] = j;
            ++rank[j];
        }
    }

    bool connected(int u, int v) { return find(u) == find(v); }

    void reset(int u) { id[u] = u; }

private:
    vector<int> id;
    vector<int> rank;
    int find(int u) { return id[u] == u ? u : id[u] = find(id[u]); }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        UnionFind uf(n);
        map<int, vector<pair<int, int>>> timeToMeeting;

        uf.unionByRank(0 , firstPerson);


        for(const vector<int>& meeting: meetings)
            timeToMeeting[meeting[2]].push_back({meeting[0], meeting[1]});

        for (const auto& [_, members] : timeToMeeting) {
            unordered_set<int> people;

            for(const auto& [x, y] : members){
                uf.unionByRank(x, y);
                people.insert(x);
                people.insert(y);
            }

            for(const int person : people){
                if(!uf.connected(person, 0)){
                    uf.reset(person);
                }
            }
        }
        vector<int> ans;

        for(int i = 0; i<n; i++){
            if(uf.connected(i, 0))
                ans.push_back(i);
        }

        return ans;
    }
};