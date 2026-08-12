class Solution {
public:
    struct Project {
        int profit;
        int capital;

        Project(int profit, int capital) : profit(profit), capital(capital){};
    };

    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        priority_queue<Project, vector<Project>,
                     decltype(  [](const Project& a, const Project& b) {
                           return a.capital > b.capital;
                       })>
            minHeap;

        priority_queue<Project, vector<Project>,
                      decltype( [](const Project& a, const Project& b) {
                           return a.profit < b.profit;
                       })>
            maxHeap;

        for (int i = 0; i < profits.size(); ++i) {
            minHeap.emplace(profits[i], capital[i]);
        }
        while (k--) {
            while (!minHeap.empty() && minHeap.top().capital <= w) {
                maxHeap.push(minHeap.top()), minHeap.pop();
            }
            if (maxHeap.empty())
                break;
            w += maxHeap.top().profit, maxHeap.pop();
        }

        return w;
    }
};