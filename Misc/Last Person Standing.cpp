#include <bits/stdc++.h>
using namespace std;
int main(){
	int numberofpeople;
	cin>>numberofpeople;
	queue<int> helper;
	for( int i = 1 ; i <= numberofpeople ; i++ ){
		helper.push(i);
	}
	while( helper.size() > 2 ){
		helper.push(helper.front());
		helper.pop(); helper.pop();
	}
	cout<<helper.front();
	return 0;
}
