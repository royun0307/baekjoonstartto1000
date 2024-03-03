#include <iostream>
#include <vector>
#include <algorithm>

class SpecialForce {
public:
	SpecialForce(int _size, int _w):size(_size), w(_w) {
		startcase = -1;
		result = 999999;
		a = new int[size];
		b = new int[size];
		c = new int[size + 1];
	}
	void SetEnemy(){
		int enemy_num;
		for (int i = 0; i < 2; i++)
		{
			std::vector <int> x;
			for (int j = 0; j < size; j++)
			{
				std::cin >> enemy_num;
				x.push_back(enemy_num);
			}
			enemy.push_back(x);
		}
	}
	void solve() {
		if (size == 1) {
			startcase = 0;
			setInitalValue();
			std::cout << result << std::endl;
			return;
		}
		int up = enemy[0][0] + enemy[0][size - 1];
		int down = enemy[1][0] + enemy[1][size - 1];
		startcase = 0;
		setInitalValue();
		if(up <= w) {
			startcase = 1;
			setInitalValue();
		}
		if (down <= w) {
			startcase = 2;
			setInitalValue();
		}
		if(up <= w && down <= w) {
			startcase = 3;
			setInitalValue();
		}
		std::cout << result << std::endl;
		return;
	}
	void setInitalValue(){
		switch (startcase)
		{
		case 0:
			a[0] = 1;
			b[0] = 1;
			c[0] = 0;
			getMinForceNum(0);
			result = std::min(result, c[size]);
			return;
		case 1:
			a[1] = 2;
			if (enemy[1][0] + enemy[1][1] <= w) {
				b[1] = 1;
			}
			else {
				b[1] = 2;
			}
			c[1] = 1;
			getMinForceNum(1);
			result = std::min(result, b[size - 1] + 1);	
			return;
		case 2:
			if (enemy[0][0] + enemy[0][1] <= w) {
				a[1] = 1;
			}
			else {
				a[1] = 2;
			}
			b[1] = 2;
			c[1] = 1;
			getMinForceNum(1);
			result = std::min(result, a[size - 1] + 1);
			return;
		case 3:
			a[1] = 1;
			b[1] = 1;
			c[1] = 0;
			getMinForceNum(1);
			result = std::min(result, c[size - 1] + 2);
			return;
		default:
			return;
		}
	}
	void getMinForceNum(int num) {
		for (int i = num; i < size; i++)
		{
			c[i + 1] = std::min(a[i] + 1, b[i] + 1);

			if (enemy[0][i] + enemy[1][i] <= w) {
				c[i + 1] = std::min(c[i + 1], c[i] + 1);
			}

			if (i > 0 && enemy[0][i] + enemy[0][i - 1] <= w && enemy[1][i] + enemy[1][i - 1] <= w) {
				c[i + 1] = std::min(c[i + 1], c[i - 1] + 2);
			}

			if (i < size - 1) {
				a[i + 1] = c[i + 1] + 1;
				b[i + 1] = c[i + 1] + 1;

				if (enemy[0][i] + enemy[0][i + 1] <= w) {
					a[i + 1] = std::min(a[i + 1], b[i] + 1);
				}
				if (enemy[1][i] + enemy[1][i + 1] <= w) {
					b[i + 1] = std::min(b[i + 1], a[i] + 1);
				}
			}
		}
	}
private:
	int size;
	int w;
	int startcase;
	int result;
	std::vector <std::vector <int>> enemy;
	int* a;
	int* b;
	int* c;
};

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, w;
		std::cin >> n >> w;
		SpecialForce specialforce(n, w);
		specialforce.SetEnemy();
		specialforce.solve();
	}

	return 0;
}
