#include <iostream>
#include <cstdlib>
using namespace std;

void fun(int *a, int size){
	int ones = 0, zeros = 0;
	for(int i = 0; i < size; i++){
		if(a[i])
			ones++;
		else
			zeros++;
	}
	cout << "Ones: " << ones << "\nZeros: " << zeros << endl;
}
int main(int argc, char* argv){
	int usr;
	cin >> usr;
	srand(time(NULL));
	int *a = new int[usr];
	for(int i = 0; i < usr; i++){
		a[i] = rand()%2;
	}
	fun(a,usr);
	delete [] a;
}
