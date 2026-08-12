class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for (const int num : arr)
            ++mp[num];
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto it = mp.begin(); it != mp.end(); it++)
            pq.push(it->second);
        while (k > 0) {
            k -= pq.top(), pq.pop();
        }

        return pq.size() + (k < 0 ? 1 : 0);
    }
};