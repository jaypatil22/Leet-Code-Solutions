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
    ListNode* reverse(ListNode* t) {
        ListNode *prev=nullptr,*next = nullptr;
        while(t) {
            next = t->next;
            t->next = prev;
            prev = t;
            t= next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode *h1=head,*h2=head,*t1=nullptr,*t2;
        while(--left) {
            t1 = h1;
            h1 = h1->next;
        }
        while(--right) {
            h2 = h2->next;
        }
        t2 = h2->next;
        h2->next = nullptr;
        if(t1) t1->next = reverse(h1);
        else {
            head = reverse(h1);
            t1 = head;
        }   
        while(t1->next) {
            t1 = t1->next;
        }
        t1->next = t2;
        return head;
    }
};