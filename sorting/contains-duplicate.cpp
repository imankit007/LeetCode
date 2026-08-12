class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        set<int> numSet;

        for(const int num : nums){
            if(numSet.find(num) != numSet.end()){
                return true;
            }
            numSet.insert(num);
        }


        return false;
    }
};