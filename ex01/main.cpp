#include "span.hpp"
#include <algorithm>
#include <vector>

#define CAPACITY 10000
int main(void) {
  {
    std::cout << "=============== [ Custom Test ] =============\n\n";
    unsigned int *arr;

    arr = new unsigned int[CAPACITY];
    srand(time(NULL));
    for (int i = 0; i < CAPACITY; i++) {
      arr[i] = rand();
    }

    std::vector<unsigned int>           vect(arr, arr + CAPACITY);
    Span                                span(10000);
    std::vector<unsigned int>::iterator vi;
    try {
      span.addNumber(vect.begin(), vect.end());
      std::cout << span.shortestSpan() << std::endl;
      std::cout << span.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    Span dupSpan = span;
    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;
    std::cout << "\n==============================================\n\n";
  }
  {
    std::cout << "=============== [ Subject Test ] =============\n\n";
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "\n==============================================\n\n";
  }
}