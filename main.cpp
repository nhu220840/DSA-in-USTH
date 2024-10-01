#include <iostream>
#include <bitset>

int CountIntegralDevided = 0;

struct Number{
	int integral;
	double fractional;
}number;

std::bitset<64> IntegraltoBinary(int n) {
	std::bitset<64> BitArray;
	int index = 0;
	while (n) {
		BitArray.set(index, n % 2);
		n /= 2;
		index++;
	}
	CountIntegralDevided = index;
	return BitArray;
}

std::bitset<64> FractionaltoBinary(double fractional) {
	std::bitset<64> BitArray;
	int index = 0;
	while (fractional > 0 && index < 64) {
		fractional *= 2;
		if (fractional >= 1) {
			BitArray.set(index, 1);
			fractional -= 1;
		}
		else {
			BitArray.set(index, 0);
		}
		index++;
	}
	return BitArray;
}

int main() {
	double input; std::cin >> input;
	number.integral = static_cast<int>(input);
	number.fractional = input - number.integral;
	std::bitset<64> BitArray_integral = IntegraltoBinary(number.integral);
	std::bitset<64> BitArray_fractional = FractionaltoBinary(number.fractional);
	bool started = false;
	for (int i = CountIntegralDevided; i >= 0; --i) {
		if (BitArray_integral[i] || started) {
			std::cout << BitArray_integral[i];
			started = true;
		}
	}

	if (!started) std::cout << "0";

	std::cout << ".";
	for (int i = 0; i < number.integral; ++i) {
		std::cout << BitArray_fractional[i];
	}
	return 0;
}