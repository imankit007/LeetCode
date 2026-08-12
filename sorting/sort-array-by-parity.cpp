class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size()==1){
          return nums;
        }

        int n = nums.size();

        int l =0;
        int r = n-1;

        while(l<r ){
          cout<<l<<","<<r<<endl;
          if((nums[l]&1) && (nums[r]==0||!(nums[r]&1))){
            swap(nums[l],nums[r]);
            l++;
            r--;
          }
          if(!(nums[l]&1))
            l++;
          if(nums[r]&1)
            r--;
        }

        return nums;
    }
};