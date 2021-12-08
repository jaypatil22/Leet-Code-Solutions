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
    ListNode* partition(ListNode* head, int x) {
        ListNode d1, d2;
        ListNode *t1=&d1, *t2 = &d2;
        ListNode* temp = head;
        while(temp) {
            ListNode* next = temp -> next;
            temp -> next= nullptr;
            if(temp->val < x) {
                t1 -> next = temp;
                t1 = t1 -> next;
            } else {
                t2 -> next = temp;
                t2 = t2->next;
            }
            temp = next;
        }
        t1->next = d2.next;
        return d1.next;
    }
};