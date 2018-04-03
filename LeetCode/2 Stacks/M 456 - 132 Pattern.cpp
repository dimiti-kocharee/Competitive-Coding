/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence 
ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes 
a list of n numbers as input and checks whether there is a 132 pattern in the list.
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        /*
        In this Problem, I started traversing from right to left.
        Now, if you plot curve between the value in the nums(in Y-axis) versus 
        the poisition of that value(in X-axis), you can expect a very arbitrary
        curve with lots of ups and down, but the question is how to detect the
        132 pattern in minimum amount of time i.e., in O(n).
        
        Algorithm Procedure:-
        -Start iterating input vector( nums ) from right to left.
        -Create one stack ( named 'a3candidates' ), and one int( named 'a3').
        -now at each iteration,
            a. first compare the present value i.e., nums[i] with 'a3'. If it's
        smaller than 'a3' return true.
            b. second if its greater than a3, than go to the stack. In the stack,
        remove the top element from the stack till you find that the top of the
        stack is greater than nums[i] or the stack becomes empty.
	    c. and everytime you're removing element from the stack, update the
	a3 variable with the element that you're removing.
            d. and then push nums[i] to the stack( 'a3candidates' ).
        -at last if you have finished traversing the input and still din't find
        the pattern, return false.


        Intuition:-
        If we break the vector (curve) into pieces in such a way that each sub-
	vector( piece ) is having only one local maxima (concave curve) per 
	piece, we can easily detect the 132 component. And obviously in any 
	subvector if you are storing a1, a2 and a3 somewhere, then on that 
	particular piece of subvector:
            -a2 will be the local maxima.
            -a1 will be the least value on the left side of a2 on that particular 
	piece of subvector.
            -and a3 will be the immediate lesser value on the right side of a2
	( note that in the right side, it is possible that the immediate value is 
	equal to a2).
        	then you'll detect the 132 pattern whether it's there or not.
            But what if in the vector, a1, a2 and a3 doesn't lie in the same 
	subvector?
        We need to find some better idea.
        Now, here comes the role of the stack. It will store all the a3 probable
	candidates in the stack, which would be compared with a1 to detect 132 
	pattern. Now, the question is how to do it?
            It's very simple. Here is the Plan:-
            -As there might be a possibility that a1, a2 and a3 lie at different 
	subvectors, and as we're traversing from right to left, at every point 
	we'll check either the present integer is an a3 probable integer, or is 
	it a1, which we're actually looking for. 
            -If the present point is a1 ( i.e., num[i] < a3 ) then we have detected 
	the pattern.
            -If the present point might be a3( i.e., nums[i] >= a3 ) we'll store it 
	in the stack for future.

        Time Complexity:- O(n)
        Space Complexity:- O(n)

        */
        int a3 = -2147483648, numsLength = nums.size();

        std::stack<int> a3candidates;
        if( !nums.empty() ) a3candidates.push( nums[ numsLength - 1 ]);
        
        for( int i = numsLength - 2 ; i >= 0 ; i-- ){
            if( nums[i] < a3 ) return true;
            while( !a3candidates.empty() ){
                if( nums[i] <= a3candidates.top() ) break;
                a3 = a3candidates.top();
                a3candidates.pop();     
            }
            a3candidates.push( nums[i] );
        }
        
        return false;
    }
};
