/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        Node *res = nullptr,*prev=nullptr,*temp = head;
        while(temp) {
            Node* nn = new Node(temp->val);
            if(!res) res = nn;
            if(prev) prev->next = nn;
            prev = nn;
            m[temp] = nn;
            temp = temp ->next;
        }
        temp = head;
        while(temp) {
            m[temp]->random = m[temp->random];
            temp = temp ->next;
        }
        return res;
    }
};