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
class Solution
{
public:
    unordered_map<int, int> m;
    TreeNode *rec(vector<int> &preorder, vector<int> &inorder, int l, int r, int &i)
    {
        if (l > r || i >= preorder.size())
            return nullptr;
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = rec(preorder, inorder, l, m[root->val] - 1, i);
        root->right = rec(preorder, inorder, m[root->val] + 1, r, i);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        int j = 0;
        return rec(preorder, inorder, 0, preorder.size() - 1, j);
    }
};