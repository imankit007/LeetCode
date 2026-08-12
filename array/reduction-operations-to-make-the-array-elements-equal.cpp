class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int prev = nums[0];
        for(int i =1; i< nums.size();i++){
            if(nums[i]==prev)
              continue;
              prev = nums[i];
            ans+=(nums.size() - i);
        }
      return ans;
    }
};