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
    int sumRootToLeaf(TreeNode* root,int cur = 0) {
        if(!root) return 0;
        cur = cur*2 + root->val;
        if(!root->left && !root->right) res += cur;
        sumRootToLeaf(root->left,cur);
        sumRootToLeaf(root->right,cur);
        return res;
    }
};