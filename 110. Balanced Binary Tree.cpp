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

    int helper(TreeNode* root) {
        if(!root) return 0;
        return max(helper(root->right),helper(root->left)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(helper(root->left)-helper(root->right)) <= 1;

    }
};

static const auto speedup = []() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
    }();
