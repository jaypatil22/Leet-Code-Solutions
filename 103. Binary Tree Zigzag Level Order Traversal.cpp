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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int> > res;
        q.push(root);
        q.push(nullptr);
        int j=1;
        while(!q.empty()&&q.front()!=nullptr) {
            vector<int> current;
            for(;q.front()!=nullptr;) {
                auto a = q.front();q.pop();
                current.emplace_back(a->val);
                if(a->right) q.push(a->right);
                if(a->left) q.push(a->left);
            }
            q.pop();
            q.push(nullptr);
            if(j%2) {
                reverse(current.begin(),current.end());
            }
            j++;
            res.emplace_back(current);
        }
        return res;
    }
};