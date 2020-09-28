#include<iostream>
using namespace std;
int main(){
	char a = 65;
	for(a; a < 91; a++)
		cout << a << endl;
	a = 97;
	for(a; a < 123; a++)
		cout << (int) a << " = " << a << endl;
}
