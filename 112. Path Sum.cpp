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

    bool dfs(TreeNode* root, int sum,int current) {
        if(root == nullptr) {
            return false;
        }
        if(root->left == nullptr && root->right == nullptr) {
            if(current + root->val == sum)
                return true;
            else
                return false;
        }
        return dfs(root->left,sum,current+root->val) || dfs(root->right,sum,current+root->val);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root,sum,0);
    }
};
