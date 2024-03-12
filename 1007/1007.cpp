#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Coordinate
{
	int x;
	int y;
	bool isFront;
};

class VectorMatching {
public:
	VectorMatching(int _size): size(_size) {
		result = 9999999.000000;
		setVector();
	}

	void setVector() {
		int x, y = 0;
		Coordinate temp;
		for (int i = 0; i < size; i++)
		{
			std::cin >> x >> y;
			temp.x = x;
			temp.y = y;
			temp.isFront = false;
			vector_set.push_back(temp);
		}
	}
	
	void combination(int depth, int next) {
		if (depth == size / 2) {
			result = std::min(result, getVectorSum());
		}
		for (int i = next; i < size; i++)
		{
			vector_set[i].isFront = true;
			combination(depth + 1, i + 1);
			vector_set[i].isFront = false;
		}
	}

	double getVectorSum() {
		double x = 0;
		double y = 0;

		for (int i = 0; i < size; i++)
		{
			if (vector_set[i].isFront) {
				x += vector_set[i].x;
				y += vector_set[i].y;
			}
			else {
				x -= vector_set[i].x;
				y -= vector_set[i].y;
			}
		}
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	void getResult() {
		std::cout << result << std::endl;
	}
private:
	int size;
	std::vector <Coordinate> vector_set;
	double result;
};

int main() {
	int t, n;
	std::cout << std::fixed;
	std::cout.precision(10);
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		VectorMatching vectormatching(n);
		vectormatching.combination(0, 1);
		vectormatching.getResult();
	}

	return 0;
}
