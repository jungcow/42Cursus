#include "easyfind.hpp"

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};

	vector<int> vi(arr, arr+(sizeof(arr)/sizeof(int)));
	std::cout << easyfind(vi, 2) << std::endl;
	return (0);
}
