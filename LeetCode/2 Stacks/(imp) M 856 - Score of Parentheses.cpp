/*
Given a balanced parentheses string S, compute the score of the string based on the following rule:
	1. () has score 1
	2. AB has score A + B, where A and B are balanced parentheses strings.
	3. (A) has score 2 * A, where A is a balanced parentheses string.s

Note:
	1. S is a balanced parentheses string, containing only ( and ).
	2. 2 <= S.length <= 50
*/


class Solution {
/*
Here in this problem we can observe that if there is "()" somewhere, where brackets closes immediately,
that pair will score according to their layer number.
Elaboration:-
Assume "(())" :- here is only one pair lying in the second layer i.e () lyin inside one (). So the 'score' is 2^1 = 2.
Likewise (((()))) :- here is one pair lying under 3 layers. so  the 'score' is 2^3 = 8.
	So now we know that number of layers corresponds to the score of the parenthesis as 2^no.of layers.

So what if the parentheses get more sophisticated like say "((()((())))())"
	So just count the number of () pairs, here it is 3, and their individual layers. Here the first one is in the
layer no. 2 and second one in the layer no. 4 and the third one in the layer no. 1. So the 'score' will be 2^2 + 2^4 + 2^1 = 22.

Also we can use << operator which calculates power of 2 without using powf(). 
*/
public:
    int scoreOfParentheses(string S) {
        int ans = 0, layerDepth = 0;
        for(int i = 0; i < S.length() ; i++){
            layerDepth = (S[i] == '(')? layerDepth+1 : layerDepth-1;			//this is used to calculate the layer
            if( i > 0 && S[i] == ')' && S[i-1] == '(' ) 				//if there is () pair detection
            	ans += 1<<layerDepth;							// score =  score + 2^no.ofLayers
        }
        return ans;
    }
};
