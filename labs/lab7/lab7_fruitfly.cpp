#include <iostream>
using namespace std;


int main(){
	int jar[5], i_largest = 0, i_smallest = 0;
	cout << "Hello Scientists! You have 5 jars to fill with fruit flies.\n";
	for(int i = 0; i < 5; i++){
		cout << "How many fruit flies would you like in jar " << i + 1 << ": ";
		cin >> jar[i];
	}
	

	for(int i = 1; i < 5; i++){
		if(jar[i] > jar[i_largest])
			i_largest = i;
		else if(jar[i] < jar[i_smallest])
			i_smallest = i;
	}
	cout << "The jar with the most fruit flies: jar " << i_largest + 1
		<< "\nThe jar with the least fruit flies: jar " << i_smallest + 1;
	return 0;
}
