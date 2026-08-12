class Solution {
public:
    int solve(vector<int>& nums, int l, int r, int key){
      if(l>r){
        return -1;
      }
      int mid = (l+r)/2;

      if(nums[mid]==key){
        return mid;
      }
      if(nums[l]<=nums[mid]){
        if(key>=nums[l] && key<=nums[mid]){
            return solve(nums,l, mid-1,key);
        }
        return solve(nums,mid+1,r,key);
      }
      if(key>=nums[mid] && key<=nums[r])
        return solve(nums,mid+1,r, key);
      
      return solve(nums,l, mid-1, key);
    }

    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
          int mid = (l + r) /2;

          if(nums[mid]==target){
            return mid;
          }
          if(nums[l]<=nums[mid]){
            if(target>=nums[l] && target<nums[mid])
              r = mid-1;
            else
              l =mid+1;
          }else{
            if(nums[mid]<target && target<=nums[r]){
              l = mid+1;
            }else{
              r= mid-1;
            }
          }
        }

        return -1;
        
    }
};