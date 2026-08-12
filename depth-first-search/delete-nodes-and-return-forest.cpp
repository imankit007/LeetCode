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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        dfs(root, {to_delete.begin(), to_delete.end()}, true, ans );
        return ans;
    }

    TreeNode* dfs(TreeNode* root, unordered_set<int>&& to_delete, bool isRoot, vector<TreeNode*>& ans){
        
        if(root == nullptr)
            return nullptr;
        bool deleted = to_delete.count(root->val);
        if(isRoot && !deleted )
            ans.push_back(root);
        
        root->left = dfs(root->left, move(to_delete), deleted, ans);

         root->right = dfs(root->right, move(to_delete), deleted, ans);

        return deleted ? nullptr : root;
    }
};