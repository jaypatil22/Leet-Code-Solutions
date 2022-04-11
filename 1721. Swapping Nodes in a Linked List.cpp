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
    ListNode* swapNodes(ListNode* head, int k) {
        stack<ListNode*> st;
        ListNode* temp = head;
        for(int i=1;i<k;i++) {
            temp = temp->next;
        }
        ListNode* temp1 = head;
        while(temp1) {
            st.push(temp1);
            temp1 = temp1->next;
        }
        for(int i = 1;i<k;i++) {
            st.pop();
        }
        int t = temp->val;
        temp->val = st.top()->val;
        st.top()->val = t;        
        return head;
    }
};