#include <iostream>

using std::cout;

int main(int argc, const char *argv[])
{
	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		std::string str;
		str = argv[i];
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		cout << str;
	}
	cout << std::endl;
	return (0);
}
