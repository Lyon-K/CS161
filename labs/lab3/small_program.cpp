#include <iostream>
using namespace std;
int main(){
	int choice;
	cout << "Do you like vim(1 = yes; 2 = no)? ";
	cin >> choice;
	if(choice == 0)
		cout << "You hate vim!";
	else if(choice == 1)
		cout << "You love vim!";
	else
		cout << "I dont get you!";
	cout << endl;
}
