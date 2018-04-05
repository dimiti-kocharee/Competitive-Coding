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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
/*
Complexity:- O(n)
Intuition:-
Assume that the lists are intersecting! Divide the list into 3 parts
L1:-from headA till the node of intersection(length = A)
L2:- from headB till the node of intersection(length = B)
L3:- from the node of intersection till the end(length = C)
	Now we need two traverser, say cur1 and cur2.
Now if we want cur1 and cur2 to meet at the point of intersection, then 
we can do either of the two things:-
1. Compare A and B, if A is greater than B, then start cur1 from headA+(A-B)
and cur2 from headB. They both will meet at the point of intersection.
OR
2. Let cur1 first traverse through L1 then L3 then L2, and Let cur2 first traverse
through L2 then L3 then L1, then they'll meet at the node of intersection.

There are two popular approaches:-
Approach 1:-
	Traverse through the two lists if their lengths are equal,
and if they meet each other, then return the node where they intersected. 
But wait!! what if the lengths are not equal?? We'll make it equal!! Simple!! :P
First calculate both the lengths, and then find the difference(lets say x).
Now for longer node, instead of traversing from its head, first move x nodes 
foreward and then start traversing.(so that they both traverse equal amount of 
node till it reaches null)

Approach 2:- 
	Create two traverser(let's say cur1 and cur2). Now, start traversing
cur1 through list1 and cur2 through list2. And if anyone(or both) of them reach
the end of the corresponding lists, interchange the list through which they are
traversing, for eg., if cur1 traversed list1 till the end and cur2 is still 
traversing, start traversing cur1 through list2 this time, and as cur2 reaches the end
of the list2, start traversing cur2 through list1. And if they still don't meet,
before they reach the end then return NULL, whereas, if they meet, then return the node.
*/
        if( !headA || !headB ) return NULL;
        int flagA = 0, flagB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(1){
            if( curA == curB ) return curA;
            if( !curA->next && flagA == 0 ) {
                curA = headB;
                flagA = 1;
            }else if( !curA->next && flagA ==1 ) return NULL;
            else curA = curA->next;
            if( !curB->next && flagB == 0 ){
                curB = headA;
                flagB = 1;
            }else if( !curB->next && flagB == 1) return NULL;
            else curB = curB->next;            
        }
    }
};
