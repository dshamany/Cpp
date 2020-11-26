#include <iostream>
#include <map>
#include <string>


int main(int argc, const char *argv[]) {
	std::map<std::string, int> dict;
	std::string name;
	int n = 0, number;
	std::cin >> n;
	for (int i = n; i > 0; --i){
		std::cin >> name >> number;
		auto p = std::pair<std::string, int>(name, number);
		dict.insert(p);
	}

	while (std::cin >> name){
		if (name.empty()) return 0;
		if (dict.count(name) > 0){
			auto it = dict.find(name);
			std::cout << it->first << "=" << it->second << std::endl;
		} else {
			std::cout << "Not found" << std::endl;
		}
	}

	return 0;
}
