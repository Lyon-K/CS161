#include <iostream>
#include <cstdlib>
using namespace std;

bool fun(int a[][3], int size){
	int num = a[0][0] + a[1][1] + a[2][2];
	int t;
	cout << num;
	for(int i = 0; i < 3; i++){
		if(a[i][0] + a[i][1] + a[i][2] != num
				||a[0][i] + a[1][i] + a[2][i] != num)
			return false;
	}
	if(a[0][2] + a[1][1] + a[2][0] != num)
		return false;
	return true;
}
int main(){
	srand(time(NULL));
	while(true){
		int box[3][3] = {{2,7,6},{9,5,1},{4,3,8}};
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				box[i][j] = rand()%9 + 1;
		cout << endl << endl;
		if(fun(box, 3))
			cout << "TRUE";
		else 
			cout << "FALSE";
		cout << endl;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++)
				cout << box[i][j] << " ";
			cout << endl;
		}
		if(fun(box, 3))
			return 0;
	}
}

