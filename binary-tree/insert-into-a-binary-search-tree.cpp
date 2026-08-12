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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        root = insert(root, val);

        return root;
    }

    private:
    TreeNode* insert(TreeNode* root, int val){
        if(root==NULL){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }else
        if(val<root->val)
           root->left =  insert(root->left, val );
        else{
           root->right = insert(root->right, val);
        }
        return root;
    }
};