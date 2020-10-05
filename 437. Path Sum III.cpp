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

    int dfs(TreeNode* root, int sum, int current) {
        if(!root)
            return 0;
        current += root->val;
        return (current == sum) + dfs(root->left,sum,current) + dfs(root->right,sum,current);
    }

    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        return dfs(root,sum,0) + pathSum(root->left,sum) + pathSum(root->right,sum);
    }
};
