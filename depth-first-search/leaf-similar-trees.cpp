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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> tree1 = flatten(root1);
        vector<int> tree2 = flatten(root2);

        const int n = tree1.size();
        const int m = tree2.size();

        if(m!=n) return false;
        for(int i =0; i<n; i++){
            if(tree1[i]!=tree2[i])
                return false;
        }
        return true;
    }


private: 
    vector<int> flatten(TreeNode* root){
        vector<int> leaf;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr!=NULL || !s.empty()){        
            while(curr!=NULL){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();

            if(curr->left==NULL && curr->right == NULL){
                leaf.push_back(curr->val);
            }
            curr = curr->right;
        }
    return leaf;
    }
};