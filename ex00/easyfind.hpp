#ifndef _EASYFIND_H__
#define _EASYFIND_H__

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
unsigned int easyfind(vector<T> vi, int n) {

	vector<int>::iterator it;

	if (it = find(vi.begin(), vi.end(), n) == vi.end())
		std::cout << "no\n";
	std::cout << "yes\n";	
}



#endif
