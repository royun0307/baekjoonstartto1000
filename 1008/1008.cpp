#include <iostream>

double division(double a, double b) {
	return a / b;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout.precision(10);
	std::cout << division(a, b) << std::endl;
	return 0;
}
