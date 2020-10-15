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

    void helper(vector<int> &s,TreeNode* root) {
        if(root->left)
            helper(s,root->left);
        s.emplace_back(root->val);
        if(root->right)
            helper(s,root->right);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> s1,s2,res;
        if(root1)
            helper(s1,root1);
        if(root2)
            helper(s2,root2);
        int i =0,j=0;
        while(i<s1.size() && j<s2.size()) {
            if(s1[i] == s2[j]) {
                res.emplace_back(s1[i]);
                i++;
            } else if(s1[i] < s2[j]) {
                res.emplace_back(s1[i]);
                i++;
            } else {
                res.emplace_back(s2[j]);
                j++;
            }
        }
        while(i<s1.size()) {
            res.emplace_back(s1[i]);
            i++;
        }
        while(j<s2.size()) {
            res.emplace_back(s2[j]);
            j++;
        }
        return res;
    }
};

static const auto speedup = []() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
    }();
