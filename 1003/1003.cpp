#include <iostream>
#include <array>
class FibonacciNode {
public:
	FibonacciNode() {
		call_zero = -1;
		call_one = -1;
		flag = -1;
	}
	void SetCallZero(int num) {
		call_zero = num;
	}
	int GetCallZero() {
		return call_zero;
	}
	void SetCallOne(int num) {
		call_one = num;
	}
	int GetCallOne() {
		return call_one;
	}
	void SetFlag() {
		flag = 1;
	}
	int GetFlag() {
		return call_one;
	}

private:
	int call_zero;
	int call_one;
	int flag;
};


class MemoryFibonacci {
public:
	MemoryFibonacci(int _size) {
		size = _size + 1;
		memory = new FibonacciNode[size];	
		memory[0].SetCallZero(1);
		memory[0].SetCallOne(0);
		memory[1].SetCallZero(0);
		memory[1].SetCallOne(1);
	}
	void Fibonacci(int num) {
		if (memory[num].GetFlag() != -1) {
			return;
		}
		else{
			if (memory[num - 1].GetFlag() == -1) {
				Fibonacci(num - 1);
			}

			int call_zero = memory[num - 1].GetCallZero() + memory[num - 2].GetCallZero();
			memory[num].SetCallZero(call_zero);

			int call_one = memory[num - 1].GetCallOne() + memory[num - 2].GetCallOne();
			memory[num].SetCallOne(call_one);

			memory[num].SetFlag();
			return;
		}
	}

	void Print(int num) {
		Fibonacci(num);
		std::cout << memory[num].GetCallZero() << " " << memory[num].GetCallOne() << std::endl;
		return;
	}
private:
	FibonacciNode *memory;
	int size;
};

int main() { 
	int size = 40;
	int T;
	int N;
	MemoryFibonacci memory_fibonacci(size);
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		std::cin >> N;
		memory_fibonacci.Print(N);
	}
	return 0;
}
