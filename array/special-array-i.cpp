class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool last = nums[0] & 1;
        
        for(int i =1 ; i< nums.size(); ++i ){
            if(last == (nums[i]&1)){
                return false;
            }
            last = nums[i]&1;
        }

        return true;
    }
};