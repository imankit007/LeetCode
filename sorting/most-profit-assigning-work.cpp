class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        const int numberOfJobs = difficulty.size();
        const int numberOfWorkers = worker.size();
        vector<pair<int ,int>> orderByDifficulty;
        int ans = 0;
        for(int i =0; i<numberOfJobs; ++i){
            orderByDifficulty.push_back(make_pair(difficulty[i], profit[i]));
        }
        sort(orderByDifficulty.begin(), orderByDifficulty.end(),
         [](const auto &a, const auto &b){    
                return a.first < b.first;
        });
        ranges::sort(worker);
        int i = 0;
        int curr = 0;
       for(const int cap : worker ){
            while(i< numberOfJobs && cap >= orderByDifficulty[i].first){
                curr = max(curr, orderByDifficulty[i].second);
                i++;
            }   
            ans += curr;
       }
        return ans;
    }
};