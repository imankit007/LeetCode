class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        int dp =0;
        const int n = nums.size();
        for(int l=0; l<n; l++){
          if(nums[l]>threshold){
              dp =0;
          }else if(l>0 && dp>0 && nums[l]%2!=nums[l-1]%2 && nums[l]<=threshold){
              dp++;
          }else{
              dp = nums[l]%2==0? 1: 0;
          }
          ans= max(ans, dp);
        }
        return ans;
    }
};