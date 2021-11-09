/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *res = head,*temp = head;
        while(temp) {
            Node *child;
            if(temp->child) {
                child = flatten(temp->child);
                Node *next = temp->next;
                temp->next = child;
                child->prev = temp;
                while(child->next) {
                    child = child->next;
                } 
                child->next = next;
                if(next) next ->prev = child;
                temp ->child = nullptr;
                temp = next;
            } else {
                temp = temp ->next;
            }
        }
        return res;
    }
};