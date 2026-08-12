class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans =0;
        int l =0;
        multiset<int> s;

        for(int r = 0; r< nums.size(); ++r){
            s.insert(nums[r]);
            while(*s.rbegin() - *s.begin()>limit){
                s.erase(s.find(nums[l++]));
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};