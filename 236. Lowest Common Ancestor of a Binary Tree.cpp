/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *r=nullptr;
    vector<bool> helper(TreeNode *root,TreeNode*p,TreeNode*q) {
        if(!root) return {false,false};        
        vector<bool> left = helper(root->left,p,q);
        vector<bool> right = helper(root->right,p,q);
        vector<bool> res(2);
        res[0] = (p==root) || left[0] || right[0];
        res[1] = (q==root) || left[1] || right[1];
        if(!r && res[0] && res[1]) {
            r = root;
            // flag = true;
        }
        return res;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool flag=false;
        helper(root,p,q);
        return r;
    }
};