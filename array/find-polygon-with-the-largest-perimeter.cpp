class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans = -1;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        long long perimeter = 0;

        for(int side: nums)
            perimeter+=side;
        
        int i= 0;
        while( i < nums.size() &&perimeter-nums[i]<= nums[i]){
            perimeter-= nums[i++];
        }
        return perimeter==0 ? -1 : perimeter;
    }
};