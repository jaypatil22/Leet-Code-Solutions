/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        auto r = root;
        while(root && root->left) {
            auto a = root->left;
            while(root) {
                root->left->next = root->right;
                root->right->next = root->next ? root->next->left : nullptr;
                root = root->next;
            }
            root=a;
        }
        return r;
    }
};