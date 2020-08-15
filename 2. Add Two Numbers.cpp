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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        int carry=0,sum= 0;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* previous = nullptr;
        while(h1 != nullptr && h2 != nullptr) {
            sum = h1->val + h2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* current = new ListNode(sum);
            if(head == nullptr) {
                head= current;
                previous = current;
                current->next = nullptr;
            } else {
                previous->next = current;
                previous = current;
                current->next = nullptr;
            }
            h1 = h1->next;h2 = h2->next;
        }

        while(h1 != nullptr) {
            sum = h1->val + carry;
            carry = sum /10;
            sum = sum%10;
            ListNode* current = new ListNode(sum);
            if(head == nullptr) {
                head= current;
                previous = current;
                current->next = nullptr;
            } else {
                previous->next = current;
                previous = current;
                current->next = nullptr;
            }
            h1 = h1->next;
        }
        while(h2 != nullptr) {
            sum = h2->val + carry;
            carry = sum /10;
            sum = sum%10;
            ListNode* current = new ListNode(sum);
            if(head == nullptr) {
                head= current;
                previous = current;
                current->next = nullptr;
            } else {
                previous->next = current;
                previous = current;
                current->next = nullptr;
            }
            h2 = h2->next;
        }

        while(carry != 0) {
            ListNode* current = new ListNode(carry);
            previous->next = current;
            previous = current;
            current->next = nullptr;
            carry /= 10;
        }

        return head;
    }
};
