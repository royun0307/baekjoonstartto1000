#include <iostream>

int sub(int a, int b) {
	int c = a - b;
	return c;
}

int main() {
	int a = 0;
	int b = 0;
	std::cin >> a >> b;
	std::cout << sub(a, b) << std::endl;
	return 0;
}