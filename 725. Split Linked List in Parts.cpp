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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp) {
            n++;
            temp = temp->next;
        }
        int rem = n%k,div = n/k;
        vector<ListNode*> res;
        temp = head;
        for(int i=1;i<=k;i++) {
            if(!temp) {
                res.push_back(temp);
            } else {
                int cnt = div;
                if(i<=rem) cnt++;
                res.push_back(temp);
                ListNode* prev;
                while(temp && cnt--) {
                    prev = temp;
                    temp = temp -> next;
                }    
                prev -> next = nullptr;
            }
            
        }
        return res;
    }
};