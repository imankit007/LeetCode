#include <vector>
#include <algorithm>
class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        
        if(nums.size()<2) return nums.size();

        int temp=0;
        int count=1;
        
        sort(begin(nums), end(nums));

      for(int i =1; i<nums.size();i++){
          if(abs(nums[i]-nums[temp])>k){
              count++;
              temp=i;
          }
      }
        return count;
    }
};