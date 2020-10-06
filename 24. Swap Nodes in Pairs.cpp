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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *temp = head,*prev=nullptr;
        while(temp && temp->next) {
            //cout<<temp->val<<" ";
            if(temp == head) {
                head = temp->next;
            }

            ListNode *t = temp->next->next,*t2=temp->next->next;
            temp->next->next = temp;
            if(prev) {
                prev -> next = temp->next;
            }
            prev = temp;
            temp->next = t;
            temp=t;

            }
        return head;
    }
};
