class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int size = nums.size();
        long ans = 0;


        long rightSum = accumulate(nums.begin(), nums.end(), 0l) ;

        long leftSum = 0;

        for(int i =0; i<size -1; ++i ){
            
            leftSum += nums[i];
            rightSum-=nums[i];

            if(leftSum >= rightSum)
                ++ans;
        }
        
        return ans;
    }
};