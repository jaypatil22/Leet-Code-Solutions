/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void pre(TreeNode* root, string &res) {
        if(!root)
            return;
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int));
        for(int i=0;i<4;i++) res.push_back(buf[i]);
        pre(root->left,res);
        pre(root->right,res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if(root)
        pre(root, res);
        //cout << res << "\n";
        return res;
    }

    TreeNode* insert(string&  data, int &pos, int mi, int ma) {
        //cout << pos << " " << sizeof(data) << "\n";
        if(pos >= data.size()) return NULL;

        int value;
        memcpy(&value, &data[pos], sizeof(int));
        if(value > ma || value < mi) return NULL;


        TreeNode* head = new TreeNode(value);
        pos += sizeof(int);
        if(pos < data.size())
            head-> left = insert(data,pos,mi,value);
        if(pos < data.size())
        head->right = insert(data,pos,value,ma);
        return head;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return insert(data, pos, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
