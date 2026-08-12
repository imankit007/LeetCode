class Solution {
public:
    int minJumps(vector<int>& nums) {
        const int n = nums.size();

        if (n == 1) {
            return 0;
        }

        int mx = *max_element(nums.begin(), nums.end());

        buildSPF(mx);

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            vector<int> pf = getPrimeFactors(nums[i]);

            for (int p : pf) {
                mp[p].push_back(i);
            }
        }

        vector<int> dist(n, -1);

        queue<int> q;
        q.push(0);

        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];
            if (i == n - 1)
                return d;

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            if (isPrime(val)) {

                for (int nxt : mp[val]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = dist[i] + 1;
                        q.push(nxt);
                    }
                }
                mp[val].clear();
            }
        }

        return -1;
    }

private:
    vector<int> spf;
    void buildSPF(int mx) {
        spf.resize(mx + 1);
        for (int i = 0; i <= mx; i++)
            spf[i] = i;

        for (int i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= mx; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    bool isPrime(int x) { return x > 1 && spf[x] == x; }
    vector<int> getPrimeFactors(int x) {

        vector<int> factors;

        if (x < 2)
            return factors;

        while (x > 1) {

            int p = spf[x];
              if (p <= 1)
                break;

            factors.push_back(p);

            while (x % p == 0)
                x /= p;
        }

        return factors;
    }
};