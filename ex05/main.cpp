#include "Karen.hpp"

int main(void) {
	Karen karen;

	karen.complain("debug");
	karen.complain("DEBUG");
	karen.complain("INFO");
	karen.complain("WARNING");
	karen.complain("ERROR");
	karen.complain("");
	return (0);
}
