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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;

        return merge(sortList(head),sortList(fast));
    }

    ListNode* merge(ListNode* l1,ListNode* l2) {
        ListNode t(0);
        ListNode *head = &t;
        while(l2 && l1) {
            if(l2->val > l1->val) {
                head->next = l1;
                head = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                head = l2;
                l2 = l2->next;
            }
        }

        if(l1) {
            head->next = l1;
        }
        if(l2) {
            head->next = l2;
        }

        return t.next;
    }

};
