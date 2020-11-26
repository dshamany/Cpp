#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

void add(const int& input, const string& name, map<string, int>& numMap){
	if (numMap.count(name) > 0){
		for (auto& i : numMap){
			if (i.first == name){
				i.second += input;
				break;
			}
		}
	} else {
		auto p = std::pair<string, int>(name, input);
		numMap.insert(p);
	}
}
void del(const string name, map<string, int>& numMap){
	numMap.erase(name);
}
void prt(const string name, map<string, int>& numMap){
	auto it = numMap.find(name);
	cout << it->second << endl;
}

void selection(int n, map<string, int>& numMap){
	string name;
	switch(n){
		case 1:
			cin >> name >> n;
			add(n, name, numMap);
		break;
		case 2:
			cin >> name;
			del(name, numMap);
		break;
		case 3:
			cin >> name;
			prt(name, numMap);
		break;
		default:
		break;
	}
}


int main() {
	map<string, int> numMap;
	int type, n;
	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> type;
		selection(type, numMap);
	}

    return 0;
}
