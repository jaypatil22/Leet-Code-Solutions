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
        ListNode* next,*prev = nullptr;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* hare = head,*tor = head;
        while(hare->next && hare->next->next) {
            tor = tor->next;
            hare = hare->next->next;
        }
        hare = reverse(tor->next);
        tor ->next = nullptr;
        tor = head;
        int res= 0;
        while(hare) {
            res = max(res,hare->val+tor->val);
            hare = hare->next;
            tor = tor->next;
        }
        return res;
    }
};