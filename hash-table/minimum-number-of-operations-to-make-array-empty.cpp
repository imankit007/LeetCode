class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int ans = 0;
        unordered_map<int, int> mp;

        for(const int n: nums)
            mp[n]++;

        for(const auto& [_, freq]: mp){

            if(freq == 1)
                return -1;
            ans+= (freq+2)/3;
        }
        return ans;
    }
};