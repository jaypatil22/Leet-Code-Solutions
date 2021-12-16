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
    void helper(TreeNode* root, int left, int right) {
        if(!root) return;
        if(root->val >= left && root->val <=right) res += root->val;
        helper(root->left,left,right);
        helper(root->right,left,right);
        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        helper(root,low,high);
        return res;
    }
};