#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;
int main()
{
 int hotel_floor;
 srand(time(NULL));
 hotel_floor = rand() % 5;
 if(hotel_floor < 1){
  cout << "You are assigned to the ground floor." << endl;
 }
else if (hotel_floor % 2 == 1){
  cout << "You are assigned to an odd floor." << endl;
 }
else{
  cout << "You are assigned to an even floor." << endl;
 }
 cout << hotel_floor << endl;
 return 0;
} 
