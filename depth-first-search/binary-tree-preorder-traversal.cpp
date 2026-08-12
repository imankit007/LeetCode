/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

private:
    void preorder(TreeNode* root, vector<int>& arr) {

        if (root == nullptr) {
            return;
        }
        arr.push_back(root->val);
        if (root->left != nullptr) {
            preorder(root->left, arr);
        }

        if (root->right != nullptr) {
            preorder(root->right, arr);
        }
    }
};