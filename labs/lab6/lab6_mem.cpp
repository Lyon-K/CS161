#include <iostream>
using namespace std;
void create_int(int*& ptr); /* pass the pointer by reference */
void create_int(int** ptr); /* pass a pointer to the pointer */
int main(){
	int *p1, **p2;
	create_int(p1);
	delete p1;
	create_int(**&p2);
	delete *p2;
	return 0;
}
void create_int(int*& ptr){
	ptr = new int;
}

void create_int(int** ptr){
	*ptr = new int;
}

