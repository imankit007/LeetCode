class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

        unordered_map<int, vector<int>> startToEndDays;

        int minDay = INT_MAX;
        int maxDay = 0;

        int ans = 0;

        for (const vector<int>& event : events) {
            int start = event[0];
            int end = event[1];
            startToEndDays[start].push_back(end);
            minDay = min(minDay, start);
            maxDay = max(maxDay, end);
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int day = minDay; day <= maxDay; ++day) {
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            for (const int& end : startToEndDays[day]) {
                minHeap.push(end);
            }

            if (!minHeap.empty()) {
                ans++;
                minHeap.pop();
            }
        }

        return ans;
    }
};