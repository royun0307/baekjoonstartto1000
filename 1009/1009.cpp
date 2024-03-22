#include <iostream>
#include <vector>

void solution(int a, int b) { 
	a = a % 10;
	b = b % 4;
	if (a == 0) {
		std::cout << 10 << std::endl;
		return;
	}
	if (b == 0)b = 4;
	int num = 1;
	for (int i = 0; i < b; i++)
	{
		num *= a;
		num = num % 10;
	}
	std::cout << num << std::endl;
	return;
}

int main() {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		std::cin >> a >> b;
		solution(a, b);
	}
	return 0;
}
