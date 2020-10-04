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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        ListNode *t1,*t2,*l,*prev;
        t1 = l1;t2= l2;l = nullptr;
        while(t1 != nullptr && t2 != nullptr) {
            if(t1->val < t2->val) {
                if(l == nullptr) {
                    l = t1;
                    prev = t1;
                    t1 = t1->next;
                } else {
                    prev->next = t1;
                    prev = t1;
                    t1 = t1->next;
                }
            } else {
                if(l == nullptr) {
                    l = t2;
                    prev = t2;
                    t2 = t2->next;
                } else {
                    prev->next = t2;
                    prev = t2;
                    t2 = t2->next;
                }
            }
        }
        while(t1 != nullptr) {
            prev->next = t1;
            prev = t1;
            t1 = t1->next;
        }
        while(t2 != nullptr) {
            prev->next = t2;
            prev = t2;
            t2 = t2->next;
        }

        return l;
    }
};
