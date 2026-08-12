class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long ans = 0;
        int mod = 1e9+7;
    unordered_map<int ,long> m;
        for(int i=0;i<nums.size(); i++){
           ++m[nums[i] - reverse(nums[i])];
        }
        
      for(auto [first, second]: m){
        ans= (ans + (second*(second-1)/2)) % mod;
      }

    return ans;
    }

    int reverse(int num){
      int ans =0;

      while(num){
        int d = num % 10;
        ans = (ans*10) + d ;
        num /=10;
      }
      return ans;
    }
};