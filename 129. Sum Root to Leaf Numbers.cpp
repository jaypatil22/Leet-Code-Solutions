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
    int sum = 0;
    void helper(TreeNode* root, int num) {
        if(!root) return;
        num = num*10 + root->val;
        if(root->right == nullptr && root->left == nullptr) sum += num;
        helper(root->left,num);
        helper(root->right,num);
    }
    int sumNumbers(TreeNode* root) {
        int num = 0;
        helper(root,num);
        return sum;
    }
};