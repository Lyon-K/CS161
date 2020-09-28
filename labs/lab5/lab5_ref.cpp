/*******************************************************************
 * ** Function: plus_10_value
 * ** Description: adds 10 to a variable
 * ** Parameters: usr
 * ** Pre-Conditions: takes in a user input
 * ** Post-Conditions: adds 10 to the user's input and display it
 * *******************************************************************/ 
#include <iostream>
using namespace std;
int plus_10_value(int n){
	return n + 10;
}
void plus_10_ref(int& n){
	n += 10;
}
int main(){
	int usr, m;
	cout << "Enter an integer: ";
	cin >> usr;
	usr = plus_10_value(usr);
	cout << "Your number plus 10 is " << usr << endl;
	cout << "Enter an integer: ";
	cin >> m;
	plus_10_ref(m);
	cout << "Your number plus 10 is " << m << endl;
	return 0;
}
