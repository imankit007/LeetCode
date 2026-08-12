struct T {
    long end;
    int room;
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> count(n);

        ranges::sort(meetings);

        auto compare = [](const T& a, const T& b){
            return a.end == b.end ? a.room>b.room: 
                a.end> b.end;
        };

        priority_queue<T, vector<T>, decltype(compare)> minHeap;

        priority_queue<int, vector<int>, greater<int>> available;

        for(int i =0; i<n; i++)
            available.push(i);

        for(const vector<int>& meeting: meetings){
            const int start = meeting[0];
            const int end = meeting[1];

            while(!minHeap.empty() && minHeap.top().end <= start)
                available.push(minHeap.top().room), minHeap.pop();

            if(available.empty()){
                const auto [newStart, roomId] = minHeap.top();
                minHeap.pop();
                count[roomId]++;
                minHeap.push({newStart + (end - start), roomId});
            }else{
                const int roomId = available.top();
                available.pop();
                count[roomId]++;
                minHeap.push({end, roomId});
            }

        }
        return ranges::max_element(count) - count.begin();
    }
};