/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = new ListNode(val-1);
        cur->next = head;
        head = cur;
        while( cur->next ){
            if( cur->next->val == val ) cur->next = cur->next->next;
            else cur = cur->next;
        }
        return head->next;
    }
};
