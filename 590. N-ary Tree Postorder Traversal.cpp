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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            Node* temp = s.top();
            s.pop();
            for(auto a : temp->children) {
                s.push(a);
            }
            res.emplace_back(temp->val);
        }
        reverse(begin(res),end(res));
        return res;
    }
};
