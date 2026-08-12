class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;


        for(const int n : nums){
            if(ans<2 || n > nums[ans-2])
                nums[ans++] = n;
        }
      
        return ans;
    }
};