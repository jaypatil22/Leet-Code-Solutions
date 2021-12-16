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
    ListNode* insert(ListNode* nh, ListNode* node) {
        if(!nh) return node;
        ListNode *temp = nh, *prev = nullptr;
        while(temp && temp->val < node->val) {
            prev = temp;
            temp = temp->next;
        }
        if(!prev) {
            node->next = nh;
            return node;
        } else {
            prev->next = node;
            node->next = temp;
            return nh;
        }
    }
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *nh = nullptr,*next;
        while(head) {
            next = head->next;
            head->next = nullptr;
            nh = insert(nh,head);
            head = next;
        }
        return nh;
    }
};