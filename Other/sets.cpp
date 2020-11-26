#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void add(const int input, set<int>& numSet){
	numSet.insert(input);
}
void del(const int input, set<int>& numSet){
	numSet.erase(input);
}
void inc(const int input, set<int>& numSet){
	if (numSet.count(input) > 0){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

void selection(int n, set<int>& numSet){
	switch(n){
		case 1:
			cin >> n;
			add(n, numSet);
		break;
		case 2:
			cin >> n;
			del(n, numSet);
		break;
		case 3:
			cin >> n;
			inc(n, numSet);
		break;
		default:
		break;
	}
}

int main(int argc, char const *argv[]) {
	set<int> numSet;
	int numOfQueries = 0;
	cin >> numOfQueries;
	int select;
	for (int i = 0; i < numOfQueries; ++i){
		cin >> select;
		selection(select, numSet);
	}
	return 0;
}
