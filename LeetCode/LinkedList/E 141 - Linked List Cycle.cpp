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
    bool hasCycle(ListNode *head) {
    	/*
    	Return false directly if the list is empty, or if the
    	list has a single node which points to null or, if the
    	list has two elements in which the second element
    	points to null.
    	*/

        if( !head || !head->next || !head->next->next ) return false;

        /*
        For more than two elements, we'll use Floyd’s Cycle-Finding algorithm.
        It states that if we iterate over a linked list using 
        two iterators (pointers) having different rate of increament,
        say one iterator iterates double the speed of the other,
        then they must meet one another (point to same node) if there exists a cycle.

	INTUITION:- 
	Imagine there is a one-way road where you can not take U-turn. How would you check
	if there is loop somewhere far or if the road has a dead end?(YOU CANNOT TAKE U-TURN)
		Okay, did you came up with the solution? Now, the best idea that Floyd and Brent 
	had found is that:-
	Let you and you're friend drive you're own cars where you're friend drives twice
	as fast as you. So you can imagine that, you and you're friend will meet, only
	if there is a loop, otherwise he'll be reaching a dead end waiting for you to
	reach him.

	PROCEDURE:-
	1.Create two listnodes, 'slow' and 'fast', and point 'slow' to the next of head
	and 'fast' to the next of 'slow'.
	2.Now start a loop where slow traverses the list as one node at a time,
	and 'fast' traverses twice the rate of that of the 'slow' i.e., skip one node
	and move to next every loop.
	3.Return true once the 'slow' and 'fast' point to the same node and return false
	if the 'fast' has reached the end of the list i.e., it is pointing to the last 
	or second last node(depending on the number of nodes to be even or odd)

        */
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while(1){
            if(fast == slow) return true;
            slow = slow->next;
            if( !fast->next || !fast->next->next) return false;
            fast = fast->next->next;
        }
    }
};
