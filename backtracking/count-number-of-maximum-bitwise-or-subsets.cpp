class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ors = accumulate(nums.begin(), nums.end(), 0, bit_or<>());
        int ans  = 0;
        dfs(nums, 0,  0,ans, ors);
        return ans;
    }

private:

void dfs(vector<int>& nums, int i , int path, int& ans , int& ors){
    if(i == nums.size()){
        if(path == ors){
            ++ans;
        }
    return;
    }

    dfs(nums, i + 1 ,path, ans, ors);
    dfs(nums, i + 1, path | nums[i],ans, ors);

}

};