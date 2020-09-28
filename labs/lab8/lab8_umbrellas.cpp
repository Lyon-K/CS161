#include <iostream>
#include <string.h>
using namespace std;

struct umbrella {
	 float length;
	  string color;
};

int main(){
	umbrella u1[3];
	int ilongest = 0;
	for(int i = 0; i < 3; i++){
		cout << "Enter length for umbrella " << i << ": ";
		cin >> u1[i].length;
		cout << "Enter color for umbrella " << i << ": ";
		cin >> u1[i].color;
	}
	for(int i = 1; i < 3; i++)
		if(u1[i].length > u1[ilongest].length)
			ilongest = i;
	cout << "The longest umbrella (index " << ilongest << ") has a length of " 
		<< u1[ilongest].length << " and is " << u1[ilongest].color << ".\n";
}
