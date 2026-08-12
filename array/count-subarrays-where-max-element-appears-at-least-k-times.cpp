class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        const int n = nums.size();
        int count = 0;
        int maxNum = ranges::max(nums);
       

        for(int i =0, j =0; j<n; ++j){
            if(nums[j]==maxNum)
                ++count;
            while(count==k){
                if(nums[i++]==maxNum)
                    --count;
            }
            ans+=i;
        }
    
    return ans;

    }
};