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
    ListNode* reverseList(ListNode* head) {
    	
        //if the list is empty or has only one node return it directly
        if(!head || !head->next) return head;

        //if the list has two nodes just point the second node to the
        //first node and first node to null and return the second node
        ListNode* cur1 = head;
        if(!head->next->next){
        	cur1 = cur1->next;
        	cur1->next = head;
        	head->next = NULL;
        	return cur1;
        }

        /*Now, for more that two nodes, here is the algorithm.
        Create one more pointer( for example cur2 )
        where cur1 is pointing to the next of head and 
        cur2 is pointing to the next of cur1 so that
        head is pointing to cur1 which is then pointing to cur2

        ------		------		------		------
        | a0 |----->| a1 |----->| a2 |----->| a3 |----->
        ------		------		------		------
		 head		 cur1		 cur2

		 Now before starting the loop first point head to NULL and then
		 point cur1 to head as shown below

					------		------		------		------
		 NULL<------| a0 |<-----| a1 |		| a2 |----->| a3 |----->
		 			------		------		------		------
		 			 head		 cur1		 cur2

		Now start the while loop till the cur2 reaches the end.
		And inside the loop you just need to do 2 things :-

		a.First point the head where cur1 is pointing then, point the cur1 
		where cur2 is pointing and finally point the cur2 to its next node.

					------		------		------		------
		 NULL<------| a0 |<-----| a1 |		| a2 |----->| a3 |----->
		 			------		------		------		------
		 			 			 head		 cur1		 cur2

		b.Secondly, point the cur1 to head.

					------		------		------		------
		 NULL<------| a0 |<-----| a1 |<-----| a2 |		| a3 |----->
		 			------		------		------		------
		 			 			 head		 cur1		 cur2
		 
		Now, think about it deeply till you realize that,
		after the loop stops, the whole list is reversed except the last one.

		----------     	 ---------- 	 ----------		 ----------		------
		| a(n-4) |<------| a(n-3) |<-----| a(n-2) |<-----| a(n-1) |		| an |----->NULL
		---------- 		 ----------		 ----------		 ----------		------
		 			 			    		head		    cur1 		 cur2

		So just before returning the reversed list i.e., cur2, just point
		the cur2 to cur1.

        */

        cur1 = cur1->next;
        ListNode* cur2 = cur1->next;
        head->next = NULL;
        cur1->next = head;
        while(cur2->next){
        	head = cur1;
        	cur1 = cur2;
        	cur2 = cur2->next;
        	cur1->next = head;
        }
        cur2->next = cur1;
        return cur2;

    }
};