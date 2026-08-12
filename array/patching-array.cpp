class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        int ans = 0;

        long long currSum = 1 ;

        int index = 0;

        while(currSum <= n){
            if(index < nums.size() && nums[index]<= currSum){
                currSum+=nums[index];
                index++;
            }else{
                ++ans;
                currSum<<=1;
            }
        }
        return ans;
    }
};