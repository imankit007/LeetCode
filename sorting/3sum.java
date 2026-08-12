class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
      Arrays.sort(nums);
        
        List<List<Integer>> answer= new ArrayList<List<Integer>>();
        
        
        for(int i =0;i<nums.length-2;i++){
            if(i>0)    
                while(i<nums.length && nums[i]==nums[i-1])   
                i++;
            if(i<nums.length && nums[i]>0)
                break;
            int j = i+1;
            int k = nums.length -1;
            
            while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            
            if(sum ==0){
                answer.add(List.of(nums[i],nums[j],nums[k])); 
                
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                
                while(j<k && nums[k]==nums[k+1]) k--;
            }else if (sum>0){
                k--;
            }else{
                j++;
            }//else
            
            
            }//while
        }//for
        
        return answer;
    }//function
}//class