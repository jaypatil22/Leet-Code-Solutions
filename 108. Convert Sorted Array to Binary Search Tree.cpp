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

    TreeNode* helper(vector<int> &nums,int start, int end) {
        if(start >= end) return NULL;
        int middle = (start+end)/2;
        TreeNode *root = new TreeNode(nums[middle]);
        root->left = helper(nums,start,middle);
        root->right = helper(nums,middle+1,end);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size());
    }
};

static const auto speed = [] () {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();
