#include <iostream>
#include <cmath>

int CalcultePlanetInOrOut(int x, int y, int cx, int cy, int r) {
	int distance_square = pow((x - cx), 2) + pow((y - cy), 2);
	int r_square = pow(r, 2);
	if (r_square >= distance_square) {
		return 0;
	}
	else {
		return 1;
	}
}

void CountPlanetInOrOut(int x1, int y1, int x2, int y2, int cx, int cy, int r, int& count) {
	int start_calculate = CalcultePlanetInOrOut(x1, y1, cx, cy, r);
	int finish_calculate = CalcultePlanetInOrOut(x2, y2, cx, cy, r);
	if ((start_calculate == 1 && finish_calculate == 1) || (start_calculate == 0 && finish_calculate == 0)) {	
	}
	else {
		count++;
	}
	return;
}

int main(){
	int t = 0;

	std::cin >> t;
	for (int  i = 0; i < t; i++)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
		int count = 0;
		int n = 0;
		std::cin >> x1 >> y1 >> x2 >> y2 >> n;

		for (int q = 0; q < n; q++)
		{
			int cx = 0;
			int cy = 0;
			int r = 0;
			std::cin >> cx >> cy >> r;
			CountPlanetInOrOut(x1, y1, x2, y2, cx, cy, r, count);
		}
		std::cout << count << std::endl;
	}
	return 0;
}
