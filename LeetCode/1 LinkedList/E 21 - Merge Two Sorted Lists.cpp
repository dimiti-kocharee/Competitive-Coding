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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(4694);
        ListNode* cur1 = head;
        while(l1&&l2){
            if( l1->val <= l2->val ){
                cur1->next = l1;
                l1 = l1->next;
                cur1 = cur1->next;
            }else{
                cur1->next = l2;
                l2 = l2->next;
                cur1 = cur1->next;
            }
        }
        if(l1) cur1->next = l1;
        else cur1->next = l2;
        return head->next;
    }
};
