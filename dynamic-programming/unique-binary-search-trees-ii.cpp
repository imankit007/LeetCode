/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return {};
        return solve(1, n);
    }

    private:
        vector<TreeNode*> solve(int min, int max){
            if(min>max)
                return {nullptr};

                vector<TreeNode*> ans;

            for(int i = min; i<=max; ++i){
                for(TreeNode* left: solve(min, i-1)){
                    for(TreeNode* right: solve(i+1, max)){
                        ans.push_back(new TreeNode(i));
                        ans.back()->left = left;
                        ans.back()->right = right;
                    }
                }
            }
            return ans;
        }
};