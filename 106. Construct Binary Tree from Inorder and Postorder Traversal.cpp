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
    TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe, unordered_map<int,int> &m) {
        if(is > ie || ps > pe) return nullptr;
        TreeNode* root = new TreeNode(postorder[pe]);
        int part = m[postorder[pe]];
        root ->left = helper(inorder,postorder, is, part-1, ps, ps +part-is-1,m);
        root -> right = helper(inorder, postorder, part+1,ie, ps+part-is, pe-1,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++) m[inorder[i]] = i;
        return helper(inorder, postorder, 0 ,inorder.size()-1, 0,postorder.size()-1,m);
    }
};