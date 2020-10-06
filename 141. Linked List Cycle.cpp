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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return false;
        ListNode *hare= head,*tor= head;
        while(hare->next != NULL && hare->next->next != NULL) {
            hare = hare->next->next;
            tor = tor->next;
            if(hare == tor)
                return true;
        }
        return false;
    }
};
