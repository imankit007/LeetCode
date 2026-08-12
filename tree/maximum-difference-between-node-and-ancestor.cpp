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
    int maxAncestorDiff(TreeNode* root) {

       return solve(root, root->val, root->val);
    }

private:
    int solve(TreeNode* root, int mini, int maxi) {

        if(root == NULL)
            return 0;

        int ans  = max(abs(root->val - mini), abs(root->val - maxi));

        mini = min(mini, root->val);
        maxi = max(maxi, root->val);

        int a = solve(root->left, mini, maxi); 
        int b = solve(root->right, mini, maxi); 

        return max(ans, max(a,b));
    }
};