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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        TreeNode *temp;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        double sum = 0.0;
        int size;
        ans.push_back((double)root->val);
        if(root!=NULL)  
        q1.push(root);


        while(!q1.empty()){
            while(!q1.empty()){
              temp = q1.front();
              q1.pop();
              if(temp->left!=NULL)
                q2.push(temp->left);
              if(temp->right!=NULL)
                q2.push(temp->right);
            }
        sum = 0;
        size = q2.size();
            while(!q2.empty()){
              temp = q2.front();
              q2.pop();
              sum+=temp->val;
              q1.push(temp);
            }
            if(size>0)
            ans.push_back((double)sum/size);
        }

        return ans;

    }
};