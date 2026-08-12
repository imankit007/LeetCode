class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        const int m = nums1.size();
        const int n = nums2.size();

        int ans  = 0;

        int i = 0 , j = 0;

        while(i < m && j < n){
            if(nums1[i] > nums2[j]){
                i++;
                continue;
            }
            ans = max(ans, j - i);
            j++;
        }

        return ans ;

    }
};