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
    TreeNode* lca(TreeNode* root, int &start, int &end) {
        if(!root) return nullptr;
        if(root->val==start || root->val == end) return root;
        TreeNode* l = lca(root->left,start,end);
        TreeNode* r = lca(root->right,start,end);
        if(l && r) return root;
        return l ? l : r;
    }
    bool getPath(TreeNode* root, int val,string &cur,string &ans) {
        if(!root) return false;
        if(val == root->val) {
            ans = cur;
            return true;
        }
        cur += "L";
        if(getPath(root->left,val,cur,ans)) return true;
        cur.pop_back();
        cur += "R";
        if(getPath(root->right,val,cur,ans)) return true;
        cur.pop_back();
        return false;
        
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lca(root,startValue,destValue);
        string path_start = "",cur = "";
        getPath(root,startValue,cur,path_start);
        string path_end = "";
        cur = "";
        getPath(root,destValue,cur,path_end);
        // int i=0;
        // while(i<path_start.size() && i<path_end.size() && path_start[i]==path_end[i]) {
        //     i++;
        // }
        // path_start = path_start.substr(i);
        // path_end = path_end.substr(i);
        string res = string(path_start.size(),'U') + path_end;
        return res;
    }
};