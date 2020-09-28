/*
 * THERE ARE BUGS IN THE FOLLOWING CODE.
 * */
#include <iostream>
using namespace std;

int main(){

	int x=3, y, num; 	//declare num & again
	char myAnswer; 
	int again; 			// change again to int value

	y = x;
	cout << "y is set to: " << y << endl;

	again = 1; 			//make again true
	while(again){
		cout << "Please input a number: ";
		cin >> x; 		//change user input to x instead of y
		if(x > y){ 		//start opening brace
			cout << "X is greater than Y\n";
			cout << "would you like to input another number?"  << endl;
			cin >> again;
		}					//close missing brace
		else{
			cout << "X is less than Y" << endl;
			cout << "would you like to input another number?"  << endl;
			cin >> again;
		}
	}
	for(x = 0; x < 10; x++)	//change x+1 to increment x++
		cout << x << endl;

	cout << "What number would you like to find the factorial for? " << endl;
	cin >> num;
	for(int x = num - 1; x > 0; x--)
			num = x * num;		//implement correct algorithm for factorial
	cout << "fact: " << num << endl;	//display factorial

	cout << "Are you enjoying cs161? (y or n) " << endl;
	cin >> myAnswer;
	if(myAnswer == 'y')	//case-specific variable & comparison symbol
		cout << "YAY" << endl;
	else
		cout << "YOU WILL SOON!" << endl;

	return 0;
}
