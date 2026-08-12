class Solution {
    public int threeSumClosest(int[] nums, int target) {
        
        List<Integer> sum = new ArrayList<Integer>();
        Arrays.sort(nums);
        int min= Integer.MAX_VALUE;
        int n = nums.length;
        
        
        for(int i =0; i<n-2;i++){
            if(i>0)
                while(i<n && nums[i]==nums[i-1])
                    i++;
            
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                int curr = nums[i]+nums[j]+nums[k];
            
                min = ((Math.abs(curr-target)<Math.abs(min-target))?curr:min)   ;
                // while(j<k && nums[j]==nums[j-1]) j++;              
                // while(j<k && nums[k]==nums[k+1]) k--; 
                
            if(curr> target){
                k--;
            }else if(curr < target){
                j++;
            }else{
                break;
            }
                
            }                  
        } 
        return min;
    }
}