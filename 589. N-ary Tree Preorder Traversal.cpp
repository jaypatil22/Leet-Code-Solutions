/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        stack<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* temp = q.top();
            q.pop();
            for(int a = temp->children.size()-1;a>=0;a--) {
                q.push(temp->children[a]);
            }
            res.emplace_back(temp->val);
        }
        return res;
    }
};
