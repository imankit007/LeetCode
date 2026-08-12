class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int,int> freq;

        for(const int n : nums){
            freq[n]++;
        }

        int ans = 0;

        for(const auto &e : freq){
           int curr = e.first;
            if( freq.contains(curr -  1)){
                ans = max(ans, e.second +freq[curr - 1]);
            }

            if(freq.contains(curr + 1)){
                ans = max(ans, e.second +freq[curr + 1]);
            }

        }

    return ans;

    }
};