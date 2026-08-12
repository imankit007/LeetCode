class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        while(ans.size() < numRows){
            vector<int> row;
            row.push_back(1);
            vector<int>  prev = ans[ans.size()-1];
            int curr = prev.size();
            while(row.size()< curr ){
               row.push_back(prev[row.size()] + prev[row.size() - 1]);
            }
            row.push_back(1);
            ans.push_back(row);
        }
        return ans;
    }
};