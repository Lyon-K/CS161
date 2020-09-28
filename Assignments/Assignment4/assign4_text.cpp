/*******************************************************************************
 * ** Program Filename:	assign4_text.cpp
 * ** Author:				Lyon Kee
 * ** Date:					20/2/2020
 * ** Description:		5 operations on a string
 * ** Input:				< 1027 char; operation options 1-5(6-quit);
 * 								swap letters; letters to count; caesar shift number
 * ** Output:				operations options; vowel = consonant or not; swapped 
 * 								string; reversed string; frequency of characters;
 * 								caesar shifted string
 * ****************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

/* return true if #vowels == #consonants */
/*******************************************************************************
 * ** Function:			check_vowel_cons
 * ** Description:		check if vowel = consonant is true
 * ** Parameters:			const char* s
 * ** Pre-Conditions:	there has to be a string inputted
 * ** Post-Conditions:	returns true if n vowels = n consonants else false
 * ****************************************************************************/
bool check_vowel_cons(const char* s);

/* change char a to char b in s */
/*******************************************************************************
 * ** Function:			letter_swap
 * ** Description:		changes char from what the user chooses to another
 * ** Parameters:			char* s, const char a, const char b
 * ** Pre-Conditions:	string without the char will not have any changes
 * ** Post-Conditions:	outputs b if a is found if not then prints the string
 * ****************************************************************************/
void letter_swap(char* s, const char a, const char b);

/* OR flip order of s and store the new string in s2 */
/*******************************************************************************
 * ** Function:			flip_str
 * ** Description:		store the reversed string into another array
 * ** Parameters:			const char* s, char* s2
 * ** Pre-Conditions:	one char string will be the same when reversed; 
 * 								user enters as requested, one char at a time
 * ** Post-Conditions:	add last char to s2, move infront and repeat s' length 
 * 								times
 * ****************************************************************************/
void flip_str(const char* s, char* s2);

/* return int array with #occurrence for each char in chars */
/*******************************************************************************
 * ** Function:			count_chars
 * ** Description:		cound frequency in the string as requested by user
 * ** Parameters:			const char* s, const char* chars
 * ** Pre-Conditions:	user has to enter < 10 characters
 * ** Post-Conditions:	returns an array of frequency corresponsing to the user 
 * 								input array
 * ****************************************************************************/
int* count_chars(const char* s, const char* chars);

/*******************************************************************************
 * ** Function:			caesar
 * ** Description:		outputs shifted character according to the shift
 * ** Parameters:			const char *s
 * ** Pre-Conditions:	user has to input >-25 & <25 (26 alphabets in english)
 * ** Post-Conditions:	if it is a character then shift it, check that it is 
 * 								valid and print it out, else print the char present
 * ****************************************************************************/
void caesar(const char *s);

/*******************************************************************************
 * ** Function:			word_count
 * ** Description:		counts the frequency of a word in the string
 * ** Parameters:			const char *s, const char *word
 * ** Pre-Conditions:	use cin for word so it terminates at a spacebar
 * ** Post-Conditions:	outputs the frequency of the occurance
 * 								(non-case sensitive)
 ******************************************************************************/
void word_count(const char *s, const char *word);

int main(){
	/****************************************************************************
	 * Min:		-2147483648
	 * Max:		2147483647
	 * Reason:	The main menu has 6 options and it is more visually pleasing to 
	 * 				represent them with int instead of char or short or long
	 ***************************************************************************/
	int choice;
	int *count_ptr = NULL;
	/****************************************************************************
	 * Min:		0 
	 * Max:		255 
	 * Reason:	switch 1 and 2 is to get 1 user input of 1 character so i used
	 * 				char. 
	 ***************************************************************************/
	char usr[1028], switch1, switch2, count_input[11];
	char *ptr = NULL;
	cout << "Enter a string(no more than 1027 characters): ";
	cin.getline(usr, 1028);
	while(true){		//shows the option until user wants to quit
		cout << "\n\n1) count vowel & consonants\n2) swap character\n3) reverse"
			"\n4) Frequency\n5) Caesar cipher\n6) Check frequency of a word!\n"
			"7) Quit\nWhich operation would you like to perform on your string?\n";
		cin >> choice;
		switch(choice){
			case 1:		//prints out = or != according to the value of return
				cout << (check_vowel_cons(usr)? 
						"\n# vowels = # consonants." : "\n# vowels != # consonants.");
				break;
			case 2:		//2nd task
				cout << "Enter which character you would like to change: ";
				cin >> switch1;
				cout << "Enter the character you would like to change it to: ";
				cin >> switch2;
				cout << "\nSwapped string;\n";
				letter_swap(usr, switch1, switch2);
				break;
			case 3:		//3rd task
				ptr = new char[1028];			//heap allocation of ptr
				flip_str(usr, ptr);
				ptr += '\0';
				cout << "\nReversed string:\n";
				for(int i = 0; ptr[i] != '\0'; i++)
					cout << ptr[i];				//print the reversed string
				delete [] ptr; ptr = NULL;		//deleting ptr
				break;
			case 4:		//4th task
				cout << "Enter up to 10 "
					"letters to find the frequency of in your string: ";
				cin.ignore();
				cin.getline(count_input, 11);
				count_ptr = count_chars(usr, count_input);	//count_ptr allocated
				for(int i = 0; count_input[i] != '\0'; i++)
					/*print out the char then the frequency of the char in string*/
					cout << count_input[i] << ") " << count_ptr[i] << endl;
				delete [] count_ptr; count_ptr = NULL;			//delete count_ptr
				break;
			case 5:		//"Be creative"
				caesar(usr);
				break;
			case 6:
				char word[100];
				cout << "Enter the word in lower case(99 characters max) "
					"you want to count: ";
				cin >> word;
				word_count(usr, word);
				break;
			case 7:		//quit
				return 0;
			default:
				cout << endl << choice << " is not a valid option!\n";
		}
		/*prints usr string everytime before the menu*/
		cout << "\nYour string: ";	
		for(int i = 0; usr[i] != '\0'; i++)
			cout << usr[i];
	}
}


bool check_vowel_cons(const char* s){
	int vowel = 0, consonant = 0;
	for(int i = 0; s[i] != '\0'; i++){
		/* checks if the character at that point is a vowel*/
		if(s[i] == 'a' ||s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u' ||
				s[i] == 'A' ||s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O' ||s[i] == 'U')
			vowel++;		//if it is vowel then increment vowel
		/* if it is not a vowel and is a letter; consonant*/
		else if(s[i] > 'a' && s[i] < 'z' || s[i] > 'A' && s[i] < 'Z')
			consonant++;	//if it is a consonant, increment consonant
	}
	cout << endl << vowel << " Vowels\n" << consonant << " Consonants\n";
	if(vowel == consonant)
		return true;
	else return false;
}

void letter_swap(char* s, const char a, const char b){
	for(int i = 0; s[i] != '\0'; i++){
		if (s[i] == a)		//a found -> print b instead
			cout << b;
		else					//not found means print the letter itself
			cout << s[i];
	}
}

void flip_str(const char* s, char* s2){
	for(int i = 0; s[i] != '\0'; i++)
		/*insert end of s into begining of s2*/
		s2[i] = s[strlen(s) - 1 - i];
}

int* count_chars(const char* s, const char* chars){
	int *temp_ptr = new int[10], count;
	for(int c = 0; chars[c] != '\0'; c++){
		count = 0;		//make count 0 on every new character
		for(int i = 0; s[i] != '\0'; i++){
			/* if the string's character is the user's character, increment count
			 **/
			if(chars[c] == s[i])
				count++;
		}
		temp_ptr[c] = count;		//insert the count into the array of frequency
	}
	return temp_ptr;
}

void caesar(const char *s){
	int shift;
	do{
		cout << "Enter the caesar shift number you would like to encrypt your "
			"string with(-25 to 25): ";
		cin >> shift;
		if(!(shift > -26 && shift < 26))
				cout << "Shift is not within the limit of (-25 to 25)!\n";
	/*checks if user input is valid*/
	}while(!(shift > -26 && shift < 26));

	for(int i = 0; s[i] != '\0'; i++){
		/*check if it is a lower case letter*/
		if(s[i] >= 'a' && s[i] <= 'z'){
			/*if shift brings it beyond the 'z' value, return it to count at 'a'*/
			if(s[i] + shift > 'z')
				cout << (char) (s[i] + shift - 26);
			/*if shift brings it beyond the 'a' value, return it to count at 'z'*/
			else if(s[i] + shift < 'a')
				cout << (char) (s[i] + shift + 26);
			/* if the shift doesnt bring the character out of the alphabet range,
			 * just print the character 
			 **/
			else
				cout << (char) (s[i] + shift);
		}

		/*check if it is a upper case letter*/
		else if(s[i] >= 'A' && s[i] <= 'Z'){
			/*if shift brings it beyond the 'Z' value, return it to count at 'A'*/
			if(s[i] + shift > 'Z')
				cout << (char) (s[i] + shift - 26);
			/*if shift brings it beyond the 'A' value, return it to count at 'Z'*/
			else if(s[i] + shift < 'A')
				cout << (char) (s[i] + shift + 26);
			/* if the shift doesnt bring the character out of the alphabet range,
			 * just print the character 
			 **/
			else
				cout << (char) (s[i] + shift);

		}
		else	//not an alphabet, print the char
			cout << s[i];
	}
}

void word_count(const char *s, const char *word){
	int count = 0;
	bool check;
	char str[1028];
	/* Stores the s string into str as all lower caps so the function will 
	 * count it as non case sensitive as requested.
	 */
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] >= 'A' && s[i] <= 'Z')
			str[i] = s[i] + ('a' - 'A');
		else
			str[i] = s[i];
	}
	str[strlen(s)] = '\0';
	for(int i = 0; str[i] != '\0'; i++)
		cout << str[i];
	cout << endl;
	for(int i = 0; i < strlen(str) - strlen(word); i++){
		check = false;
		if (str[i] == word[0]){			//compares the first lettter to each letter
			for(int j = 0; j < strlen(word); j++){		//check if each letters match
				if(str[i+j] == word[j])
					check = true;
				else{
					check = false;
					break;						//when one letter doesnt match, move on
				}
			}
		}
		if(check)								//if check still true then add 1 to count
			count++;
	}
	cout << "The word '" << word << "' appears " << count << " times!\n";
}
