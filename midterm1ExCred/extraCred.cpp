#include <iostream>
using namespace std;
int main(){
	for(char a = 's'; a <= 'v'; a++)
		for(char b = 'e'; b >= 'a'; b-=2)
			cout << a << b << endl;
	return 0;
}
