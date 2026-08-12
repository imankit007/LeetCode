class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        const int n = nums.size();
        int ans = INT_MAX;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }

        for (auto& [key, vec] : mp) {
            if (vec.size() < 3) {
                continue;
            }

            for (int i = 2; i < vec.size(); i++) {
                ans = min(ans,
                          (abs(vec[i] - vec[i - 1]) + abs(vec[i] - vec[i - 2]) +
                           abs(vec[i - 1] - vec[i - 2])));
                if(ans == 4) break;
            }
             if(ans == 4) break;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};