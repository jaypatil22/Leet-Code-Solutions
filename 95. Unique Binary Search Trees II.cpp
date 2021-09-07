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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
    
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> list;
        if(start > end) {
            list.push_back(nullptr);
        }
        for(int i=start;i<=end;i++) {
            vector<TreeNode*> right,left;
            left  = helper(start,i-1);
            right = helper(i+1,end);
            for(auto l : left) {
                for(auto r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    list.push_back(root);
                }
            }
        }
        return list;
    }
};