#include <iostream>
using namespace std;

void fun(char* a){
	for(; *a != '\0'; a++){
		if(*a >= 'a' && *a <= 'z')
			*a -= 'a' - 'A';
		else if(*a >= 'A' && *a <= 'Z')
			*a += 'a'- 'A';
	}
}

int main(int argc, char* argv[]){
	char x[256];
	cin.getline(x,256);
	fun(x);
	cout << x;
}
