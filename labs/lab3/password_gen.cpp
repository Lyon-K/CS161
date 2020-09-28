/**
 * Name:	Lyon Kee & benny ling 
 * Date:	1/24/2020
 * program:	lab3
 * fuction:	generate a password
 */
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int total, letters, lower, upper, num, rerun;
	cout << "Welcome to Password Creator!\n";
	do{
		cout << "\nHow many characters do you want the password to be? ";
		cin >> total;					//asks num of character in password
		cout << "How many letters (out of " << total << ")? ";
		cin >> letters;					//asks num of letters in password
		cout << "How many upper-case letters (out of " << letters << ")? ";
		cin >> upper;					//asks num of upper case letters
		lower = letters - upper;		//calculate num of lower case letters
		num = total - letters;			//calculates num of numbered characters
		cout << "The rest of the letters (" << lower << ") will be lower-case.\n";
		cout << "The rest of the characters (" << num << ") will be numbers.\n\n";
		cout << "Your random password is: ";
		srand(time(NULL));				//changes the position of random pointer
		for(upper; upper > 0; upper--)	//prints out upper case characters
			cout << (char) (rand() % 26 + 65);
		for(lower; lower > 0; lower--)	//prints out lower case characters
			cout << (char) (rand() % 26 + 97);
		for(num; num > 0; num--)		//print out numbers as specified
			cout << rand() %10;
		cout << "\nWould you like to create another password (0-no, 1-yes)? ";
		cin >> rerun;					//asks if the user wants to rerun
	}while(rerun == 1);					//rerun if user wants to rerun
	return 0;
}
