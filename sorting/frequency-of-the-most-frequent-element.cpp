class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

          sort(nums.begin(), nums.end());
          int ans = 0;
          long sum = 0;
          int l = 0;
          int r = 0;

          for(; r<nums.size();++r){
            sum+=nums[r];
            if(sum+k <(long)nums[r]*(r-l+1)){
              sum-=nums[l++];
            }
           
          }
      return nums.size()-l;

    }
};