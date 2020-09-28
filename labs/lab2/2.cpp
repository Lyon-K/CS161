/**********************************************************
 * ** Program: lab2_values.cpp
 * ** Authors: Both partners names
 * ** Date: 01/13/2020
 * ** Description: Calculate min/max values.
 * ***********************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int b
	long max, min, unsigned_max;
	cout << "Enter a b exponent: ";
	cin >> b;
	max = pow(2,b-1) - 1;
	min = -pow(2,b-1);
	unsigned_max = pow(2, b) - 1;
	cout << endl << "signed max: " << max << "\n signed min: " << min
		<< "\nunsigned max: " << unsigned_max << "\n";
	return 0;
}
