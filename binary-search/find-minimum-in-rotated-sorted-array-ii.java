class Solution {
    public int findMin(int[] nums) {
          
        int n= nums.length;
        
        if(nums[n-1] > nums[0] ){
            return nums[0];
        }else{
            n = n-1;
            
            while(n>=1&&nums[n-1]<=nums[n]) n--;
            
            return nums[n];
        }
        
        
        
    }
}