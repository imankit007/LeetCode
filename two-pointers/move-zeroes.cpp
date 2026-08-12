class Solution {
public:
    void moveZeroes(vector<int>& nums) {

      int ans=0;

      for(const int& num:nums){
        if(num!=0)
          nums[ans++] = num;
      }

      while(ans<nums.size())
        nums[ans++]=0;   
    
    }
};