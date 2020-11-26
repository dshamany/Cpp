#include <iostream>
#include <vector>
int main(int argc, char const *argv[]) {
	std::vector<int> v1{};
	std::vector<int> v2{1,2,3,4,5,6,7,8,9,0};

	for (auto i = 1; i < v2.size() - 1; ++i){
		v1.push_back(i);
	}
	std::cout << "  ";
	for (auto item : v1){
		std::cout << item << " ";
	}
	std::cout << " " << std::endl;

	for (auto item : v2)
		std::cout << item << " ";
	std::cout << std::endl;
	return 0;
}
