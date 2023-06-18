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
    void helper(TreeNode* root, TreeNode* &nroot, TreeNode* &parent) {
        if(!root) return;
        helper(root->left,nroot,parent);
        TreeNode* nn = new TreeNode(root->val);
        if(!parent) nroot = nn;
        else {
            parent->right = nn;
        }
        parent = nn;
        helper(root->right,nroot,parent);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* nroot = nullptr, *parent = nullptr;
        helper(root,nroot,parent);
        return nroot;
    }
};