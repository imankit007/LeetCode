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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, multiset<pair<int, int>>> nodes;

        solve(root, nodes, 0, 0);

        vector<vector<int>> ans;

        for (const auto& [_, pairs] : nodes) {
            vector<int> vals;
            for (const pair<int, int>& pair : pairs)
                vals.push_back(pair.second);
            ans.push_back(vals);
        }
        return ans;
    }

private:
    void solve(TreeNode* root, map<int, multiset<pair<int, int>>>& nodes, int x,
               int y) {
        if (root == nullptr) {
            return;
        }
        nodes[y].emplace(x,root->val);
        if (root->left != nullptr) {
            solve(root->left, nodes, x + 1, y - 1);
        }
        if (root->right != nullptr) {
            solve(root->right, nodes, x + 1, y + 1);
        }
    }
};