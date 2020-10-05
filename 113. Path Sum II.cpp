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

    void dfs(TreeNode* root, int sum,vector<int> current, int currentsum, vector<vector<int> > &res) {
        if(root == nullptr) {
            return;
        }
        current.emplace_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            if(currentsum + root->val == sum)
                res.emplace_back(current);
            return;
        }
        dfs(root->left,sum,current,currentsum+root->val,res);
        dfs(root->right,sum,current,currentsum+root->val,res);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        dfs(root, sum, {},0,res);
        return res;
    }
};
