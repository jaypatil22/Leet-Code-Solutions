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

    void helper(TreeNode* root,int x,int y,vector<TreeNode*> &m,int depth,vector<int> &d) {
        if(root->left && (root->left->val == x || root->left->val == y)) {
            m.emplace_back(root);
            d.emplace_back(depth);
        }
        if(root->right && (root->right->val == x || root->right->val == y)) {
            m.emplace_back(root);
            d.emplace_back(depth);
        }
        if(root->left)
            helper(root->left,x,y,m,depth+1,d);
        if(root->right)
            helper(root->right,x,y,m,depth+1,d);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        vector<TreeNode*> m;
        vector<int> d;
        if(root->val == x || root->val == y)
            return false;
        helper(root,x,y,m,0,d);
        return m[0] != m[1] && d[0] == d[1];
    }
};
