class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int , int> hash ; 

        for(int i =0; i< nums.size(); ++i){
            if(hash.find(target - nums[i] ) != hash.end()){
                return {i, hash.find(target - nums[i] )->second};
            }else{
                hash.insert({nums[i], i});
            }
        }

        return {0,0};

    }
};