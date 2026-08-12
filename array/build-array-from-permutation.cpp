class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        int n = nums.size();
        
        int i =0;
        
        for(int i=0; i<n;i++){
            nums[i] = nums[i] + (n * (nums[nums[i]]%n));
        }
        
        for(i=0;i<n ;i++){
            nums[i]/=n;
        }
        
        return nums;
    }
};