#include <iostream>

long long permutation(int a, int b) {
	long long result = 1;
	for (int i = a; i > b; i--)
	{
		result *= i;
	}return result;
}

long long combination(int n, int m) {
	long long result = -1;
	int min = 0;
	int max = 0;
	if (n > m - n) {
		max = n;
		min = m - n;
	}
	else {
		max = m - n;
		min = n;
	}
	result = permutation(m, max) / permutation(min, 0);

	return result;
}

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		std::cin >> n >> m;
		std::cout << combination(n, m) << std::endl;
	}
	return 0;
}
