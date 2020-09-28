/* Name: 		Lyon Kee
 * Date: 		2/13/2020
 * Lab: 			6
 * Function:	 
 */
#include <iostream>
#include <string.h>
using namespace std;
void count_punctuation(string s, int& n_periods, int& n_commas);
void count_punctuation2(string s, int* n_periods, int* n_commas);
int main(){
	string usr;
	int n_p = 0, n_c = 0;
	cout << "Enter a string:\n";
	getline(cin, usr);
	count_punctuation(usr, n_p, n_c);
	cout << "Number of periods: " << n_p << 
		"\nNumber of commas: " << n_c << endl;
	n_p = 0, n_c = 0;
	cout << endl;
	count_punctuation2(usr, &n_p, &n_c);
	cout << "Number of periods: " << n_p << 
		"\nNumber of commas: " << n_c << endl;
	return 0;
}

void count_punctuation(string s, int& n_periods, int& n_commas){
	for(int i = 0; i < s.length(); i++){
		switch(s[i]){
			case '.':
				n_periods +=1;
				break;
			case ',':
				n_commas++;
				break;
		}
	}
}


void count_punctuation2(string s, int* n_periods, int* n_commas){
	for(int i = 0; i < s.length(); i++){
		switch(s[i]){
			case '.':
				++*n_periods;
				break;
			case ',':
				*n_commas += 1;
				break;
		}
	}
}
