//Problem:- 	https://github.com/dimiti-kocharee/Competitive-Coding/blob/master/Misc/The%20Richest%20Pirate.jpg?raw=true
#include <bits/stdc++.h> 
using namespace std;

/*
Time: O(N)
Space: O(1)
algorithm(2 steps) :-
1. take the absolute sum (S) of the whole vector (vec) elements.
2. if all the elements are of same sign (ie. either +ve or -ve and contains no 0) :-
-> return S - min(vec)	:- sum minus minimum of the whole vector
else return S :- sum
Also if the size of the vector is 1, return the first number as it is!
(That is the only case you can get negative result(debt))
*/

long long richestPirate(vector<long>& pirates) {
	long long sum = 0;
	long n = pirates.size() , minp = n ? abs(pirates[0]) : 0;
	bool isZero = false, isPositive = false, isNegative = false;
	for (int i = 0; i < n; i++) {
		sum += abs(pirates[i]);
		minp = min(minp, abs(pirates[i]));
		isZero |= pirates[i] == 0;
		isPositive |= pirates[i] > 0;
		isNegative |= pirates[i] < 0;
	}
	if (!isZero && ((isPositive && !isNegative) || (!isPositive && isNegative))) {
		sum -= 2 * minp;
	}
	if (n == 1) {
		sum = pirates[0];
	}
	return sum;
}

int main() {
	long n,x;
	cin >> n;
	vector<long> pirates;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pirates.push_back(x);
	}
	cout << richestPirate(pirates) << endl;
	return 0;
}
