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
    TreeNode* helper(vector<int> &preorder, vector<int> &postorder, int prsi, int prei, int pssi,int psei, unordered_map<int, int> m) {
        if(prsi > prei || pssi > psei) return nullptr;
        TreeNode* root = new TreeNode(preorder[prsi]);
        if(prsi==prei) return root;
        int idx = m[preorder[prsi+1]];
        int tnel = idx - pssi +1;
        root -> left = helper(preorder, postorder, prsi+1, prsi+(tnel), pssi,idx,m);
        root -> right = helper(preorder, postorder, prsi+tnel+1,prei,idx+1,psei-1,m);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<postorder.size();i++) {
            m[postorder[i]] = i;
        }
        return helper(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1,m);
    }
};