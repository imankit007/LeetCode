class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        const int n = customers.size();
        double total_waiting_time = 0;
        int curr = 0;
        for(const vector<int> customer: customers){
            int arrival = customer[0];
            int time = customer[1];
            if(curr < arrival){
                 curr = arrival;
            }
            total_waiting_time += (curr - arrival) + time;
            curr+=time;
        }
        return total_waiting_time/n;
    }
};