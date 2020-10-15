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

    vector<int> res;


    void helper(TreeNode* root, int level) {
        if(!root)
            return;
        if(res.size() <= level) {
            res.emplace_back(root->val);
        } else {
            if(res[level] < root->val) {
                res[level] = root->val;
            }
        }
        helper(root->left,level+1);
        helper(root->right,level+1);
    }

    vector<int> largestValues(TreeNode* root) {
        helper(root,0);
        return res;
    }
};
