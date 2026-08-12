class Solution {
    public int findMiddleIndex(int[] nums) {
        
        int sum = 0 ;
        int i ;
        int leftSum = 0 ;
        int rightSum = 0 ;
        
        
        for(i = 0 ; i<nums.length ; i++){
           sum += nums[i];
        }
        
        rightSum = sum - nums[0];
        
        for(i = 0 ; i < nums.length; i++){
            if(leftSum == rightSum){
                return i;
            }
            
            leftSum = leftSum + nums[i];
           
            if(i < nums.length-1)
                rightSum = rightSum - nums[i+1];
                
        }
        

        return -1;
       
        
    }
}