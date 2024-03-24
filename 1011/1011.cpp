#include <iostream>
#include <cmath>

int minCount(int x, int y) {
	int distnace = y - x;
	int square_root = sqrt(distnace);
	if (distnace == pow(square_root, 2)) {
		return 2 * square_root - 1;
	}
	else if (distnace <= square_root * (square_root + 1)) {
		return 2 * square_root;
	}
	else {
		return 2 * square_root + 1;
	}
}

int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x, y = 0;
		std::cin >> x >> y;
		std::cout << minCount(x, y) << std::endl;
	}
	return 0;
}
