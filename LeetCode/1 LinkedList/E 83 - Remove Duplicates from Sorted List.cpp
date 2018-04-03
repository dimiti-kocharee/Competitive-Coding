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
    ListNode* deleteDuplicates(ListNode* head) {
//It is exactly same as the node deleting problem (237- Delete Node in a Linked List)
//We just need to traverse from head till the end and delete nodes that are 
//repeating same data more than once, in the sorted list.
        ListNode* temp = head;
        while(temp){
            if(!temp->next) break;
            if(temp->val==temp->next->val){
                temp->next=temp->next->next;
            }
            else{
// the temp only moves foreward if the values in the present node and the next node are different
                temp = temp->next;
            }
        }
        return head;
    }
};
