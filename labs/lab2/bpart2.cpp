/**********************************************************
 * ** Program: lab2_values.cpp
 * ** Authors: Lyon, Lucas Pichette (TA) : )
 * ** Date: 01/13/2020
 * ** Description: Calculate min/max values.
 * ***********************************************************/
#include <iostream>
using namespace std;
int main(){
	int max_int = 2147483647, min_int = -2147483648;
	cout << max_int << endl << min_int << endl;
	max_int += 1;
	min_int -= 1;
	cout << max_int << endl << min_int << endl;
}
