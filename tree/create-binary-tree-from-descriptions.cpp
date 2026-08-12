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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> valToNode;
            unordered_map<TreeNode*, TreeNode*> childToParent;
        for(const vector<int>& desc : descriptions){
            const int parent = desc[0];
            const int child = desc[1];
            const bool isLeft = desc[2];


            TreeNode* p = valToNode.count(parent) ? valToNode[parent] : valToNode[parent] = new TreeNode(parent);
            TreeNode* c = valToNode.count(child) ? valToNode[child] : valToNode[child] = new TreeNode(child);

            if(isLeft){
                p->left = c;
            }else{
                p->right = c;
            }
            childToParent[c] = p;
        }

        TreeNode* root = valToNode.begin()->second;

        while(childToParent[root]){
            root = childToParent[root];
        }
        return root;

    }
};