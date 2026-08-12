class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        unordered_map<int , int> count;

        for(const int n : nums1){
            ++count[n];
        }

        for(const int n : nums2){
            if(count[n]-- > 0){
                ans.push_back(n);
            }
        }
        return ans;
    }
};