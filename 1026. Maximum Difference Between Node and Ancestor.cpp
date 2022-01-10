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
    int res = 0;
    void helper(TreeNode* root, int mi, int ma) {
        if(!root) return;
        mi = min(root->val,mi);
        ma = max(root->val,ma);
        res = max(res,ma-mi);
        helper(root->left,mi,ma);
        helper(root->right,mi,ma);
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        helper(root,root->val,root->val);
        return res;
    }
};