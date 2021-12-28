/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr,*next;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *t = head, *h = head;
        while(h->next && h->next->next) {
            t = t->next;
            h = h->next->next;
        }
        ListNode* second = reverse(t->next);
        t->next = nullptr;
        ListNode *temp = head,*prev = nullptr;
        head = nullptr;
        while(temp && second) {
            ListNode *n1 = temp->next ,*n2 = second->next;
            temp->next = second;
            second->next = nullptr;
            if(!head) {
                head = temp;
            } else {
                prev->next = temp;
            }
            prev = second;
            temp = n1,second = n2;
        }
        if(temp) prev->next = temp;
    }
};