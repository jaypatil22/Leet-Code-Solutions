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
        ListNode *prev = nullptr,*next;
        while(head) {
            next = head ->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            len++;
        }
        if(len <= 2) return head;
        temp = head;
        int sum = 0;
        ListNode* pprev;
        for(int i=1;len>0;i++) {
            int l = min(i,len);
            int tl = l;
            ListNode *first = temp,*prev;
            while(l--) {
                prev = temp;
                temp = temp -> next;
            }
            ListNode* next = temp;
            prev ->next = nullptr;
            l = tl;
            if(l % 2==0) {
                pprev->next = reverse(first);
                first->next = next;
                pprev = first;
            } else {
                pprev = prev;
                prev->next = next;
            }
            len -= i;
            // cout << i << endl;
        }
        return head;
    }
};