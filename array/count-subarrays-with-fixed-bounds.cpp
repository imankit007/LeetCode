class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        const int n = nums.size();

        long long ans = 0;
        int minNum = -1;
        int maxNum = -1;
        int j = -1;
        for(int i =0; i<n; ++i){
            if(minK>nums[i] || maxK<nums[i])
                j = i;
            if(minK==nums[i])
                minNum = i;
            if(maxK == nums[i])
                maxNum = i;

            ans += max(0, min(minNum, maxNum)-j);
                
        }

       

        return ans;
    }
};