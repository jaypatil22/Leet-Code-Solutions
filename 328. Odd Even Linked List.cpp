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
    ListNode* oddEvenList(ListNode* head) {
        ListNode dod = ListNode();
        ListNode dev = ListNode();
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp -> next;
            len++;
        }
        temp = head;
        ListNode *temp1 = &dod, *temp2 = &dev;
        for(int i=1;i<=len;i++) {
            ListNode* next = temp -> next;
            if(i%2) {
                temp1 -> next = temp;
                temp1 = temp1 -> next;
                temp1 -> next = nullptr;
            } else {
                temp2 -> next = temp;
                temp2 = temp2 -> next;
                temp2->next = nullptr;
            }
            temp = next;
        }
        temp1->next = dev.next;
        return dod.next;
        
    }
};