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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0 || head->next == nullptr)
            return head;
        int i = 0,len = 1;
        ListNode* a = head;
        while(a->next) {
            a = a->next;
            len++;
        }

        while(i<k%len) {
            ListNode* temp = head,*prev = NULL;
            while(temp->next) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            temp ->next = head;
            head = temp;
            i++;
        }
        return head;
    }
};
