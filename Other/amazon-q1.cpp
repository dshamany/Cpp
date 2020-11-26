// This was an implementation for a techical interview
// at Amazon

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<int> cellCompete(int* states, int days)
{
    //Declare size
    const int SIZE = 8;
    // Copy array for safe manipulation
    std::vector<int> modified(10, 0);
    std::vector<int> previous(10, 0);
	std::copy(states, states+7, std::begin(modified)+1);
    // Loop based on number of days
    for (int n = 0; n < days; ++n){
        // Swap previous
        std::swap(previous, modified);
        // Loop through array for manupulation
        for (int i = 1; i < 9; ++i){
            // Handle neighbors
			modified[i] = previous[i-1] ^ previous[i+1];
        }
    }
    // Return vector
    return std::vector<int>(std::begin(modified) + 1, std::begin(modified) + 9);
}

int main(int argc, char const *argv[]) {
	int states[8] = {1,0,0,0,0,1,0,0}; // Dummy Array with data
	auto res = cellCompete(states, 1); // Run function

	// Print result
	for (auto i : res)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}
