#include <bits/stdc++.h>
using namespace std;

int main() {
	int tasks , deadline, profit;
	cin>>tasks;		//number of tasks
	vector<pair<int,int>> deadline_profit;	//first is deadline and second is profit
	for( int i = 0 ; i < tasks ; i++ ){
		cin>>deadline;
		cin>>profit;
		deadline_profit.push_back(make_pair(deadline,profit));
	}
  // sort the vector of pairs wrt. deadline
	sort(deadline_profit.begin(),deadline_profit.end());  
	priority_queue<int> pending_profits;
	int max_profit = 0 , current_deadline = tasks ? deadline_profit[tasks-1].first : 0 ;
  /*
  here is the main part:-
  start from the right, do the following:-
  1. put all the profits of the same deadline(current deadline) in the max_heap
  2. take the difference in the previous(greater deadline) and the current(sooner deadline) deadline and put it in k
  3. you choose k profits from the max_heap and pop those out.
  4. do this from right to left
  */
    
	for( int i = tasks-1 ; i >= 0 ; i-- ){
		while( i >= 0 && deadline_profit[i].first == current_deadline ){
			pending_profits.push(deadline_profit[i].second);
			i--;
		}
		int k = i>=0 ? current_deadline - deadline_profit[i].first : current_deadline;
		while( k-- && !pending_profits.empty()){
			max_profit += pending_profits.top();
			pending_profits.pop();
		}
		current_deadline = deadline_profit[i].first;
		i++;
	}
	cout<<max_profit<<endl;
	return 0;
}
