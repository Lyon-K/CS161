#include <iostream>
using namespace std;

/*****************************************************************************
 * ** Function: is_vowel
 * ** Description: check whether a character is a vowel
 * ** Parameters: a single character, c
 * ** Pre-conditions: c is a lower-case letter (a-z)
 * ** Post-conditions: return true if c is a vowel and otherwise false
 * ***************************************************************************/
bool is_vowel(char c){
	switch(c){
		case 'a':
			return true;
		case 'e':
			return true;
		case 'i':
			return true;
		case 'o':
			return true;
		case 'u':
			return true;
		case 'A':
			return true;
		case 'E':
			return true;
		case 'I':
			return true;
		case 'O':
			return true;
		case 'U':
			return true;
		default:
			return false;
	}
}

/*****************************************************************************
 * ** Function: swap_case
 * ** Description: generate and return the opposite case character
 * ** (lower-case => upper-case and vice-versa)
 * ** Parameters: a single character, c
 * ** Pre-conditions: c is a lower-case (a-z) or upper-case (A-Z) letter
 * ** Post-conditions: if c is lower-case, return upper-case C, and vice-versa
 * ***************************************************************************/
char swap_case(char c){
	if(c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c - ('a' - 'A');
}

int main(){
	if(is_vowel('a')) cout << "'a' is a vowel!\n";
	else cout << "'a' is not a vowel!\n";
	if(is_vowel('E')) cout << "'E' is a vowel!\n";
	else cout << "'E' is not a vowel!\n";
	if(is_vowel('b')) cout << "'b' is a vowel!\n";
	else cout << "'b' is not a vowel!\n";

	cout << "The swapped case for a is " << swap_case('a') << endl;
	cout << "The swapped case for B is " << swap_case('B') << endl;
	cout << "The swapped case for c is " << swap_case('c') << endl;
	return 0;
}
