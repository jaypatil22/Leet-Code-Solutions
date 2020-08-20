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
#include <stack>
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;
        stack<int> s;
        auto h2 = head;
        while(h2 != nullptr) {
            s.push(h2->val);
            h2 = h2 -> next;
        }

        while(!s.empty()) {
            if(s.top() != head->val) {
                return false;
            }
            head = head -> next;
            s.pop();
        }
        return true;
    }
};
