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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next)
            return nullptr;
        stack<ListNode*> s;
        ListNode* temp = head;
        while(temp != nullptr) {
            s.push(temp);
            temp = temp->next;
        }
        int pos = 1;ListNode* prev = nullptr;
        while(!s.empty()) {
            ListNode* temp = s.top();
            s.pop();
            if(pos == n)
                break;
            pos++;
            prev = temp;

        }
        if(s.empty())
            return prev;
        ListNode* a = s.top();
        a -> next = prev;
        return head;

    }
};
