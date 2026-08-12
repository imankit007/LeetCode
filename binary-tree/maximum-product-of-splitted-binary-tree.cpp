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
    int mod = 1e9+7;

    int sum(TreeNode* root, vector<long> &sums){
        if(root==NULL){
            return 0;
        }

        int left = sum(root->left, sums);
        int right = sum(root->right, sums);

        int sum = left + right + root->val;
        sums.push_back(sum);
        return sum;
    }

    int solve(TreeNode* root){
        if(root==NULL){
            return 0 ;
        }
        long ans = 0;
        vector<long> sums;
        int total = sum(root, sums);

        for(const long s: sums){
            ans = max(ans, (s * (total - s)));
        }

        return ans%mod;

    }

    int maxProduct(TreeNode* root) {
        return solve(root);
     
    }
};