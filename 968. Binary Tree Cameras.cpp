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
    long long res;
    unordered_set<TreeNode *> s;

public:
    void dfs(TreeNode *root, TreeNode *parent)
    {
        if (root)
        {
            dfs(root->left, root);
            dfs(root->right, root);

            if ((parent == nullptr && s.find(root) == s.end()) || s.find(root->left) == s.end() || s.find(root->right) == s.end())
            {
                res++;
                s.insert(root);
                s.insert(parent);
                s.insert(root->left);
                s.insert(root->right);
            }
        }
    }
    int minCameraCover(TreeNode *root)
    {
        res = 0;
        s.insert(nullptr);
        dfs(root, nullptr);
        return res;
    }
};