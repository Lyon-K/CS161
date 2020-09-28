#include <iostream>
#include <string>
using namespace std;


string pal(char c){
	if(c == 'A')
		return "A";
	else
		return pal(c-1) + c + pal(c-1);
}

int main(){
	char usr;
	cin >> usr;
	cout << pal(usr) << endl;
	return 0;
}
