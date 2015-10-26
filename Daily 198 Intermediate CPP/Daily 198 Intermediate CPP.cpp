// Daily 198 Intermediate CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void negadecimal(int& base, long& number, int index, long& result) {
	cout << "Base: " << base << "\tNumber: " << number << "\tCur result: " << result << "\tAdds: " << (number % 10 * pow(base, index)) << endl;

	if (number) {
		result += (number % 10 * pow(base, index));
		number /= 10;
		negadecimal(base, number, index + 1, result);
	}
}

void invertBase(int& base, long& number, int index, long& result) {
	cout << "Invert base: " << base << "\tNumber: " << number << "\tCur result: " << result << "\tAdds: " << (number%base)*pow(10, index) << endl;

	if (abs(number) >= abs(base)) {
		result += (abs(number%base))*pow(10, index);
		number /= base;
		invertBase(base, number, index + 1, result);
	}
	else {
		result += (abs(number%base))*pow(10, index);
	}
}

int main(int argc, char* argv[]) {
	int base = atoi(argv[1]);
	long number = atoi(argv[2]), result = (number > 0) ? 1 : -1;    // Because of how computers calculate binary (they start from 1, we start from 0),


	negadecimal(base, number, 0, result);

	if (base % 10 != 0) { // Since we've already converted it to base 10, we don't have to do anything with it.
		base = -base;
		number = result;
		result = ((number > 0) ? 1 : -1);
		invertBase(base, number, 0, result);
	}

	cout << result << endl;

	return 0;
}