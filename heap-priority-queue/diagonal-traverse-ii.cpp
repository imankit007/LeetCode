class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> m;
        int maxIndex= INT_MIN;
        for(int i =0 ;i<nums.size();i++){
            for(int j = 0; j<nums[i].size();j++){
                m[i+j].insert(m[i+j].begin(),nums[i][j]);
                maxIndex = max(maxIndex, i+j);
            }
        }

        vector<int> ans;

        for(int i =0; i<=maxIndex;i++){
            for(const int num: m[i]){
                ans.push_back(num);
            }
        }
        return ans;
    }
};