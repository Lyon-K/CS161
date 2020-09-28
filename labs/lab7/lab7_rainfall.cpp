#include <iostream>
using namespace std;

int main(){
	int size;
	double *ptr, sum = 0;
	cout << "Hello Scientists! You need to record the rainfall per city (in inches).\n"
		"How many cities would you like to record the rainfall of: ";
	cin >> size;
	ptr = new double[size];
	for(int i = 0; i < size; i++){
		cout << "How much rainfall was there in city " << i << ": ";
		cin >> ptr[i];
		sum += ptr[i];
	}
	cout << "Average rainfall per city: " << sum/size << " inches\n";
	delete ptr;
	return 0;
}
