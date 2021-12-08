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
    ListNode* deleteMiddle(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp -> next;
        }
        if(len<=1) return nullptr;
        int i=0;
        ListNode* prev = head;
        temp = head;
        while(i != len/2) {
            prev = temp;
            temp = temp -> next;
            i++;
        }
        prev -> next = temp -> next;
        return head;
    }
};