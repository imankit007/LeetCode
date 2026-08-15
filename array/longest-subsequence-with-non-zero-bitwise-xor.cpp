class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        const int n = nums.size();

        int left = 0 ; 

        int ans = 0; 

        int curr = 0;

        for(int right = 0; right < n ; right++ ){

            curr ^= nums[right];
            if(curr != 0){
                ans = max(ans, right - left + 1);
            }

            while(curr == 0 && left < right){
                curr ^= nums[left++];
            }
        }

        return ans;

    }
};