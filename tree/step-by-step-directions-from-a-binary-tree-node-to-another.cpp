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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path;
        string startToRoot ;
        string rootToDest;

        dfs(root, startValue, path,startToRoot);
        dfs(root, destValue, path,  rootToDest);
        
        cout<<startToRoot<<endl;
        cout<<rootToDest<<endl;

        int i =0;
        while((i<min(startToRoot.length(), rootToDest.length())) && startToRoot[i] == rootToDest[i])
            i++;
        
        string ans = string(startToRoot.length() - i, 'U') + string(rootToDest.begin() + i, rootToDest.end());
        return ans;
    }

    void dfs(TreeNode * root, int dest, string &path, string& ans){
        if(root==NULL)
            return;
        if(root->val == dest)
           ans = path;
        path.push_back('L');
        dfs(root->left, dest, path, ans);
        path.pop_back();
        path.push_back('R');
        dfs(root->right, dest, path, ans);
        path.pop_back();
    }
};