class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        const int n = energy.size();
        vector<int> dp(energy);
        for(int i = n-1-k; i >= 0 ; --i){
            dp[i] += dp[i + k];
        }
       return ranges::max(dp);
    }
};