#include <iostream>
#include <cstring>
using namespace std;
float star_factor(char* str);
int main(){
	char usr[20];
	cout << "Please enter a string (<20 chars):";
	cin.getline(usr,20);
	cout << "String length: " << strlen(usr) << 
		"\nStars: " << star_factor(usr)*strlen(usr)  <<
		"\nStar-factor (percentage): " << star_factor(usr)*100 << '%' << endl;

	char *longer = new char[39];
	strcat(strcat(longer, usr), usr);
	cout << "String length: " << strlen(longer) << 
		"\nStars: " << star_factor(longer)*strlen(longer) <<
		"\nStar-factor (percentage): " << star_factor(longer)*100 << '%' << endl;
	delete [] longer;
	return 0;
}
float star_factor(char* str){
	int stars = 0;
	for(int i = 0; str[i] != '\0'; i++)
		if(str[i] == '*')
			stars++;
	return (float) stars/strlen(str);
}
/* input: ***Hydra*** *Virgo*
 * output:
 * String length: 19
 * Stars: 8
 * Star-factor (percentage): 42.1052%
 *
 * input: *0
 * output:
 * String length: 2
 * Stars: 1
 * Star-factor (percentage): 50%
 *
 * input: *****AAAAA
 * output:
 * String length: 10
 * Stars: 5
 * Star-factor (percentage): 50%
 */
