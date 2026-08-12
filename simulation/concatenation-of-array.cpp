class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
     
        vector<int> res(nums);
        for(auto temp: nums)
            res.push_back(temp);
        
        

        
        
        return res;
    }
};