class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int i =0;
        int ans = ~0;
        for(; i<nums.size(); ++i){
            if(i!= nums[i]){
                ans = ans & nums[i];
            }
        }
        
        return ans == -1 ? 0 : ans;
    }
};