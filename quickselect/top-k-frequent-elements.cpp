class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;

        unordered_map<int, int> freq;

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype([](const pair<int, int> &a, const pair<int, int > &b){
            return a.second < b.second;
        })> maxHeap;

        for(const int n : nums){
            freq[n]++;
        }

        for(auto &pair : freq){
            maxHeap.push(pair);
        }

        while(k--){
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return ans;

    }
};