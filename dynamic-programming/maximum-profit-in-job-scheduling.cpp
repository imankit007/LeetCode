
struct Job{
    int start;
    int end;
    int profit;
    Job(int start, int end, int profit):start(start),end(end), profit(profit){}
};


class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        const int n =  startTime.size(); 
        
        dp.resize(n+1);
        vector<Job> jobs;

        for(int i =0; i<n; i++){
            jobs.emplace_back(startTime[i], endTime[i], profit[i]);
        }

        ranges::sort(jobs, [](const auto &a, const auto &b){
            return a.start < b.start;
        });

        for(int i =0; i<n; i++){
            startTime[i]= jobs[i].start;
        }

        return solve(jobs, startTime, 0);
    }
    private: 
        vector<int> dp;

        int solve(const vector<Job> &jobs,const vector<int> &startTime, int i){
            if(i==jobs.size())
                return 0;
            if(dp[i]>0)
                return dp[i];

            const auto j = firstMaxProfitJob(startTime, i+1, jobs[i].end);

            const auto incl = jobs[i].profit + solve(jobs,startTime,j);
            const auto excl = solve(jobs, startTime, i+1);

            return dp[i]= max(incl, excl);
        }

        int firstMaxProfitJob(const vector<int> &startTime, int start, int target){
            return lower_bound(startTime.begin()+start, startTime.end(), target) - startTime.begin();
        }
};