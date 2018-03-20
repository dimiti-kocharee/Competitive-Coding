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
    void deleteNode(ListNode* node) {
    	//the following code will delete the present node
    	//what it basically does is that it just copies the value in the next node
    	//and just point to the node where the next node is pointing to.
        node->val = node->next->val;		//copy the value in the next node
        node->next = node->next->next;		//point to the node where the next node points

        /*
        After seeing other submissions, I also came across a solution which does exactly the
        same thing but in just one line i.e., what about coping the subsequent whole structure 
        into the present node.

		*node = *(node->next);			//this is doing exactly the same thing as above

        */
    }
};