#include <iostream>
#include <cmath>

float distance(int x1, int y1, int x2, int y2) {
	int x = x1 - x2;
	int y = y1 - y2;
	float d = sqrt(pow(x, 2) + pow(y, 2));
	return d;
}

int turret(int x1, int y1, int r1, int x2, int y2, int r2) {
	float d = distance(x1, y1, x2, y2);
	if (d == 0) {
		if (r1 == r2) {
			return -1;
		}
		else {
			return 0;
		}
	}
	else {
		float r = r1 + r2;
		float abs_r = abs(r1 - r2);
		if (r == d || d == abs_r) {
			return 1;
		}
		else if (abs_r < d && d < r) {
			return 2;
		}
		else {
			return 0;
		}
	}
}

int main() {
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	int r1 = 0;
	int r2 = 0;
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		std::cout << turret(x1, y1, r1, x2, y2, r2) << std::endl;

	}

	return 0;
}