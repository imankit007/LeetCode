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

    vector<int> solve(TreeNode* root){
      if(root==NULL)  return {0,0,0};

      vector<int> left = solve(root->left);
      vector<int> right = solve(root->right);

      vector<int> ans(3,0) ;
      ans[1] = left[1] + right[1] + root->val;
      ans[2] = left[2] + right[2] + 1;
      
      int avg = ans[1]/ans[2];
      ans[0] = left[0] + right[0] + (avg==root->val?1:0);

      return ans;

    } 

    int averageOfSubtree(TreeNode* root) {
      vector <int> ans = solve(root);

      return ans[0];  
    }
};