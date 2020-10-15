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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> cur;
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if(!temp) {
                res.emplace_back(cur);
                if(q.empty())
                    return res;
                q.push(nullptr);
                cur.clear();
                continue;
            }
            cur.emplace_back(temp->val);
            for(auto a : temp->children) {
                q.push(a);
            }
        }
        return res;
    }
};
