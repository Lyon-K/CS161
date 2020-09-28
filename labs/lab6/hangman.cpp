#include <iostream>
using namespace std;
void get_input(string* s);
void hide_letters(const string& s, string* s_hidden); 
int guess_letter(char letter, const string& s, string* s_hidden);

int main(){
	string hidden, temp;
	char guess;
	int rem;
	cout << "Enter a secret string using only lower-case letters: ";
	get_input(&temp);
	const string usr = temp;
	for(int i = 0; i < 50; i++)
		cout << endl;
	hide_letters(usr, &hidden);
	for(int i = 0; i < hidden.length(); i++)
		if(hidden[i] == '*')
			rem++;
	while(rem > 0){
		cout << "Your string is: " << hidden;
		cout << "\nPlease guess a letter : ";
		cin >> guess;
		cout << guess_letter(guess, usr, &hidden) << " matches!\n\n";
		rem -= guess_letter(guess, usr, &hidden); 
	}
	cout << "The string is: " << usr << endl;
	return 0;
}	

void get_input(string* s){
	getline(cin, *s);
}

void hide_letters(const string& s, string* s_hidden){
	for(int i = 0; i < s.length(); i++){
		if(s[i] != ' ')
			*s_hidden += '*';
			else
			*s_hidden += ' ';
	}
}

int guess_letter(char letter, const string& s, string* s_hidden){
	int count = 0;
	for(int i = 0; i < s.length(); i++){
		if(letter == s[i]){
			count++;
			(*s_hidden)[i] = s[i];
		}
	}
	return count;
}
