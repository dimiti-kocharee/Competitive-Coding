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
    bool isPalindrome(ListNode* head) {
/*
In this problem the easiest method(to be solved in linear time:yet best),
is to compare the first and the last node values, second and second last node values,
and so on till we reach the middle of the list.
Now, how to do that?
-break the list into two halves.
-reverse any one of the list.
-start comparing from the heads.
*/
        if( !head || !head->next ) return true;
        bool isPalindrome1 = true;
        ListNode* cur = head;
        int length=1;
        while(cur->next){
            cur = cur->next;
            length++;
        }
        cur = head;
/*
Reversing the second half
*/
        for(int i = 0; i < length/2-1 ;i++) cur = cur->next;
        ListNode* tail = cur->next;
        cur->next = NULL;
        ListNode* cur1 = tail;
        ListNode* cur2 = tail;
        ListNode* cur3 = tail;
        if( cur1->next && !cur1->next->next ){
            cur2 = tail->next;
            cur1->next = NULL;
            cur2->next = cur1;
            tail = cur2;
        }else if( cur1->next && cur2->next->next ){
            cur1 = tail;
            cur2 = cur1->next;
            cur3 = cur2->next;
            cur1->next = NULL;
            while( cur3->next ){
                cur2->next = cur1;
                cur1 = cur2;
                cur2 = cur3;
                cur3 = cur3->next;
            }
            cur2->next = cur1;
            cur3->next = cur2;
            tail = cur3;
        }
/*
Check for similarity of the divided list
*/
        cur1 = head;
        cur2 = tail;
        while(cur1->next){
            if( cur1->val != cur2->val ) { 
                isPalindrome1 = false;
                break;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        if( cur1->val != cur2->val ) isPalindrome1 = false;
/*
This will just make the list same as the initial state
*/
        cur1 = tail;
        cur2 = tail;
        cur3 = tail;
        if( cur1->next && !cur1->next->next ){
            cur2 = tail->next;
            cur1->next = NULL;
            cur2->next = cur1;
            tail = cur2;
        }else if( cur1->next && cur2->next->next ){
            cur1 = tail;
            cur2 = cur1->next;
            cur3 = cur2->next;
            cur1->next = NULL;
            while( cur3->next ){
                cur2->next = cur1;
                cur1 = cur2;
                cur2 = cur3;
                cur3 = cur3->next;
            }
            cur2->next = cur1;
            cur3->next = cur2;
            tail = cur3;
        }
        cur->next = tail;
        return isPalindrome1;
    }
};
