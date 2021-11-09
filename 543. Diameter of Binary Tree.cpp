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
    int max;
    int helper(TreeNode* root) {
        if(!root) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        if(left + right > max) max = left + right;
        return left > right ? left + 1 : right + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        max = 0;
        helper(root);
        return max;
    }
};