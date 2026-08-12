class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        const int size = nums.size();
        if(k==0){
          return nums;
        }
        vector<int> ans(size,-1);
        if(size<(2*k)+1){
          return ans;
        }
          int start =0, end= (2*k);
          long sum =0;
          for(int i = start; i<=end;i++){
            sum+=nums[i];
          }
          int i= k;
            ans[i++]= sum/((2*k)+1);
          for(; i<size-k; i++){
            sum = sum - nums[start++] + nums[++end];
            ans[i]= sum/((2*k)+1);
          }
        return ans;
    }
};