class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        unordered_set<int> uniqNums(nums.begin(), nums.end());


        while(uniqNums.contains(original)){
            original*=2;
        }


        return original;
    }
};