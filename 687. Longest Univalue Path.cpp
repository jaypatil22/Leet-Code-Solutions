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

    int dfs(TreeNode* root, int &len) {
        int left = root->left ? dfs(root->left,len) : 0;
        int right = root->right ? dfs(root->right,len) : 0;
        int r1 = root->left && root->left->val == root->val ? left+1 : 0;
        int r2 = root->right && root->right->val == root->val ? right+1 : 0;
        len = max(len,r1+r2);
        return max(r1,r2);

    }

    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
        int len=0;
        dfs(root,len);
        return len;
    }
};
