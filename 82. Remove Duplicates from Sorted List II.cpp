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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *cur = head->next,*prev = head;
        while(head && head->next && head->val == head->next->val) {
            prev = head;
            while(head && prev->val == head->val) {
            head = head->next;
        }
        }
        if(head && head->next) {
            cur = head->next,prev = head;
        while(cur) {
            while(cur && cur->next && cur->val == cur->next->val) {
                ListNode *prev1= cur;
           while(cur && prev1->val == cur->val) {
               cur = cur->next;
           }
            }
            prev->next = cur;
            prev = cur;
            if(cur)
                cur = cur->next;
        }
        }
        return head;
    }
};
