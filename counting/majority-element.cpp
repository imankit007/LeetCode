class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int prev ;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
          if(count == 0){
            prev = nums[i];
            count = 1;
          }else{
                if(nums[i] == prev){
                    ++count;
                }else{
                    --count;
                }
          }
        }
        return prev;
    }
};