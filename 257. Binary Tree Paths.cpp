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

    void dfs(vector<string> &res, TreeNode* root,string current) {
        if(root == nullptr) {
            //res.emplace_back(current);
            return;
        }
        if(root->left == nullptr && root->right == nullptr) {
            current += to_string(root->val);
            res.emplace_back(current);
            return;
        } else {
            current += to_string(root->val) + "->";
        }
        dfs(res,root->left,current);
        dfs(res,root->right,current);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(res, root, "");
        return res;
    }
};
