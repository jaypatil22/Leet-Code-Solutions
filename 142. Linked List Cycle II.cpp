/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return NULL;
        ListNode *hare = head,*tor = head;
        while(hare->next != NULL && hare->next->next != NULL) {
            hare = hare->next->next;
            tor = tor->next;
            if(hare == tor)
                goto here;
        }
        return NULL;

        here:
        int pos = 0;
        hare = head;
        while(hare != tor) {
            hare = hare -> next;
            tor = tor->next;
            pos++;
        }
        return hare;
    }
};
