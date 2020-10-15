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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int sum = 0;
        while(!q.empty()) {
            if(!q.front()) {
                q.pop();
                if(q.empty())
                    return sum;
                else {
                    sum=0;
                    q.push(nullptr);
                    continue;
                }
            }
            TreeNode *t = q.front();
            q.pop();
            sum += t->val;
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        return -1;
    }
};
