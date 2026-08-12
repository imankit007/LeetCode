class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      
      if(nums.size()<3)
        return false;
      int min1 = INT_MAX;
      int min2 = INT_MAX;

      for(const int& num:nums){
        if(num<min1)
          min1 = num;
        if(num>min1){
          min2 = min(min2, num);
        }
        if(num>min2)
          return true;
        
      }
     return false;
    
    }
};