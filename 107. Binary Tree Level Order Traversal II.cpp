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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> cur;
        vector<vector<int> > res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()) {
            if(q.front()==nullptr) {
                q.pop();
                res.emplace_back(cur);
                cur.clear();
                if(q.empty())
                    break;
                else{
                    q.push(nullptr);
                }
            }
            TreeNode* temp = q.front();
            q.pop();
            cur.emplace_back(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        vector<vector<int> > res1;
        for(int i = res.size()-1;i>=0;i--) {
            res1.push_back(res[i]);
        }
        return res1;
    }
};

static const auto speed = [] () {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();
