class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;
        for(const int& num: nums){
            if((num & 1) == 0){
                ans = ans | num;
            }
        }

        return ans;
    }
};