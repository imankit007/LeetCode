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
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }

    private:
        int solve(TreeNode* root, const int& low,const int& high){
            if(root==NULL){
                return 0;
            }
            int sum = 0;
            if(root->val>=low && root->val<=high){
                sum+=root->val;
            }

            sum+= solve(root->left, low, high);
            sum+=solve(root->right, low, high);

            return sum; 
        }
};