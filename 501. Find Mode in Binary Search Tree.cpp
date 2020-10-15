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
    int prev= INT_MIN,currfreq=0,max = INT_MIN;
    vector<int> res;

    void helper(TreeNode* root) {
        if(root==NULL) return;
        helper(root->left);
        if(prev == root->val) currfreq++;
        else currfreq = 1;
        if(currfreq > max) {
            res.clear();
            res.emplace_back(root->val);
            max = currfreq;
        } else if(currfreq == max) {
            res.emplace_back(root->val);
        }
        prev = root->val;
        helper(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        if(root==NULL)
            return res;
        helper(root);
        return res;
    }
};
