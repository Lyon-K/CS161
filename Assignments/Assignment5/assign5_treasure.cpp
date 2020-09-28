/*******************************************************************************
 * ** Program Filename:	assign5_treasure.cpp
 * ** Author:				Lyon Kee
 * ** Date:					3/7/2020
 * ** Description:		collect room keys and store it in a "treasure chest" and
 * 								operations that it could run
 * ** Input:				treasure chest size, room name, floor, beds, cost, 
 * 								existence of tv
 * ** Output:				treasure chest with item names, value of item, show 
 * 								every attribute of an item
 * ****************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*******************************************************************************
 * used a string for name because it can take in a string of characters
 * used it for floor and beds because it is a valid range to contain for the 
 * 	existing realistic range of out world
 * cost is a value with decimal value so I made it a float
 * tv is a boolean of weather it is there or not so it can be represented as 
 * 	true or false with booleean
 ******************************************************************************/
struct room{
	string name;
	int floor;
	int beds;
	float cost;
	bool tv;
};

/*******************************************************************************
 * ** Function:			add_key_p2
 * ** Description:		allows the usr to add a key at a spefied empty position
 * ** Parameters:			chest, rows& columns of chest, value of chest, usr_row,
 * 								usr_column
 * ** Pre-Conditions:	position has to be valid, name cant be blank, floor has
 * 								to be realistic, beds has to be an integer, cost cant
 * 								be negative or 0, tv has to be true or false
 * ** Post-Conditions:	adds the item into the chest
 * ****************************************************************************/
void add_key_p2(room **c, int row, int col, float &v, int &usrr, int &usrc){
	do{
		cout << "Enter a name for your room: ";
		cin.ignore();
		getline(cin, c[usrr][usrc].name);
	}while(c[usrr][usrc].name.empty());	//make sure name not blank
	/*checks if floor is between -20 and 180 and show prompt if it is not */
	do{
		cout << "Enter which floor the room " << c[usrr][usrc].name
			<< " exists on: ";
		cin >> c[usrr][usrc].floor;
		if(c[usrr][usrc].floor < -20 || c[usrr][usrc].floor > 180)
			cout << "This floor is not within the physics of this world!\n"
				"Keep it between -20 to 180 floors";
	}while(c[usrr][usrc].floor < -20 || c[usrr][usrc].floor > 180);
	cout << "Enter the number of beds in your room: ";
	cin >> c[usrr][usrc].beds;	//let user enter num of beds in the room
	do{
		cout << "Enter the cost of your room: ";
		cin >> c[usrr][usrc].cost;
		if(c[usrr][usrc].cost <= 0)
			cout << "The cost of a room cant be free or a donation!!\n";
	}while(c[usrr][usrc].cost <= 0);	//cost cannot be 0 or negative
	v += c[usrr][usrc].cost;	//adds the cost to the total value
	cout << "Does your room have a tv?(0-no, 1-yes) ";
	cin >> c[usrr][usrc].tv;	//either have a tv or dont have one
}

/*******************************************************************************
 * ** Function:			add_key
 * ** Description:		allows the usr to add a key at a spefied empty position
 * ** Parameters:			chest, rows& columns of chest, value of chest
 * ** Pre-Conditions:	position has to be valid, name cant be blank, floor has
 * 								to be realistic, beds has to be an integer, cost cant
 * 								be negative or 0, tv has to be true or false
 * ** Post-Conditions:	adds the item into the chest
 * ****************************************************************************/
void add_key(room **c, int row, int col, float &v){
	int usrr, usrc;
	cout << "Enter row: ";
	cin >> usrr;	// gets the row the user wants to add to
	cout << "Enter column: ";
	cin >> usrc;	//gets the column the user wants to add to
	usrr--;			// make it an index
	usrc--;			//make it an index
	/*check for invalid inputs and prompts*/
	if(usrr >= row || usrc >= col || usrr < 0 || usrc < 0) 
		cout << "Invalid location within the treasure chest!\n";
	else if(!c[usrr][usrc].name.empty())
		cout << "There is aleady an item at the position!\n";
	else	//if indexes are valid then run the code to get attributes
		add_key_p2(c, row, col, v, usrr, usrc);
}

/*******************************************************************************
 * ** Function:			remove_key
 * ** Description:		removes a room key from the box if it exists
 * ** Parameters:			chest, row& columns of chest, value of items
 * ** Pre-Conditions:	user will enter an integer row and column
 * ** Post-Conditions:	removes an item from the location / tell user invalid
 * ****************************************************************************/
void remove_key(room **c, int row, int col, float &v){
	int usrr, usrc;
	cout << "Enter row: ";
	cin >> usrr;	// gets the row the user wants to add to
	cout << "Enter column: ";
	cin >> usrc;	////gets the column the user wants to add to
	usrr--;	//make it an index
	usrc--;	//make it an index
	/*check for invalid inputs and prompts*/
	if(usrr >= row || usrc >= col || usrr < 0 || usrc < 0){
		cout << "The position is not a valid location "
			"within the treasure chest!\n";
	}
	else if(c[usrr][usrc].name.empty())
		cout << "There is nothing to remove at this location...\n";
	else{ //if indexes are valid then delete the name which marks it empty
		c[usrr][usrc].name = "";
		cout << "An item was removed from the location:\nRow: " << usrr + 1 
			<< "\nColumn: " << usrc + 1 << endl;
		v -= c[usrr][usrc].cost;	//subtract the cost because it is removed
	}
}

/*******************************************************************************
 * ** Function:			random_key
 * ** Description:		create random attributes for a position
 * ** Parameters:			chest, row& columns of chest, total value of items
 * ** Pre-Conditions:	location has to be empty and in the chest
 * ** Post-Conditions:	generate an item in the location with a specified name
 * ****************************************************************************/
void random_key(room **c, int row, int col, float &v){
	int usrr, usrc;
	cout << "Enter row: ";
	cin >> usrr;	// gets the row the user wants to add to
	cout << "Enter column: ";
	cin >> usrc;	////gets the column the user wants to add to
	usrr--;	//make it an index
	usrc--;	//make it an index
	/*check for invalid inputs and prompts*/
	if(usrr >= row || usrc >= col || usrr < 0 || usrc < 0){
		cout << "The position is not a valid location "
			"within the treasure chest!\n";
	}
	else if(!(c[usrr][usrc].name.empty()))
		cout << "There is aleady an item at the position!\n";
	else{	//if indexes are valid then delete the name which marks it empty
		do{
			cout << "Enter a name for the room you would like to generate: ";
			cin.ignore();
			getline(cin, c[usrr][usrc].name);
		}while(c[usrr][usrc].name.empty());	//makes sure name is not blank
		c[usrr][usrc].floor = rand()%201 - 20;	//range is -20 to 180
		c[usrr][usrc].beds = rand() % 5;	//range is 0-4
		/*range is 0.01 to 100.01*/
		c[usrr][usrc].cost = rand() % 100000 / 100 + 0.01;
		v += c[usrr][usrc].cost;	//add cost to value
		c[usrr][usrc].tv = rand() % 2;	//either true or false
	}
}

/*******************************************************************************
 * ** Function:			show_key
 * ** Description:		show attribute of an item
 * ** Parameters:			chest, row& columns of chest, total value of items
 * ** Pre-Conditions:	only show attribute for items that exist
 * ** Post-Conditions:	shows name, floor, beds,, cost, tv existance
 * ****************************************************************************/
void show_key(room **c, int row, int col, float &v){
	int usrr, usrc;
	cout << "Enter row: ";
	cin >> usrr;	// gets the row the user wants to add to
	cout << "Enter column: ";
	cin >> usrc;	////gets the column the user wants to add to
	usrr--;	//make it an index
	usrc--;	//make it an index
	/*check for invalid inputs and prompts*/
	if(usrr >= row || usrc >= col || usrr < 0 || usrc < 0){
		cout << "The position is not a valid location "
			"within the treasure chest!\n";
	}
	else if(c[usrr][usrc].name.empty())
		cout << "There isn't an item at the position!\n";
	else{	//prints all attributes of the room
		cout << "Name: " << c[usrr][usrc].name << endl;
		cout << "Floor: " << c[usrr][usrc].floor << endl;
		cout << "Beds: " << c[usrr][usrc].beds << " per night" << endl;
		cout << "Cost: " << c[usrr][usrc].cost << endl;
		cout << "TV: " 
			<< (c[usrr][usrc].tv ? "included" : "not included") << endl;
	}
}

/*******************************************************************************
 * ** Function:			clear_key
 * ** Description:		clear all items of the chest when called
 * ** Parameters:			chest, row& columns of chest, total value of items
 * ** Pre-Conditions:	only clear chest that has things in it
 * ** Post-Conditions:	clear chest & set value to 0
 * ****************************************************************************/
void clear_key(room **c, int row, int col, float &v){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(!c[i][j].name.empty()){	//if item exists, clear and prompt
				cout << "An item named " << c[i][j].name 
					<< " have been lost at the position:\nRow: " 
					<< i + 1 << "\nColumn: " << j + 1 <<endl << endl;
				c[i][j].name = "";
			}
		}
	}
	v = 0;	//value becomes 0 after everything is cleared
}

/*******************************************************************************
 * ** Function:			d_shift
 * ** Description:		shifts the price of items because of an economic shift
 * ** Parameters:			chest, row& columns of chest, total value of items
 * ** Pre-Conditions:	only changes position that had items
 * ** Post-Conditions:	increases / decreases the value of all the items
 * ****************************************************************************/
void d_shift(room **c, int row, int col, float &v){
	/*range of -20 to 19.99 for the increase or decrease of value*/
	float shift = (float) (rand() % 2000 - 1000) / 100;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			c[i][j].cost += c[i][j].cost * shift/100;	//increase value for all item
		}
	}
	v += v * shift/100;	//updates value depending on the shift and prompt
	cout << "The economic shift made prices to shift " << shift 
		<< "\% of their original price.\n";
}

void rename(room **c, int row, int col, float &value){
	int usrr, usrc, usr;
	cout << "Enter row: ";
	cin >> usrr;	// gets the row the user wants to add to
	cout << "Enter column: ";
	cin >> usrc;	////gets the column the user wants to add to
	usrr--;	//make it an index
	usrc--;	//make it an index
	/*check for invalid inputs and prompts*/
	if(usrr >= row || usrc >= col || usrr < 0 || usrc < 0){
		cout << "The position is not a valid location "
			"within the treasure chest!\n";
	}
	else if(c[usrr][usrc].name.empty())
		cout << "There isn't an item at the position!\n";
	else{	//ask the user for the new name
		do{
			cout << "Enter a new name for your room: ";
			cin.ignore();
			getline(cin, c[usrr][usrc].name);
		}while(c[usrr][usrc].name.empty());	//make sure name not blank
	}
}



int main(){
	int row, col, menu;
	float value = 0;
	srand(time(NULL));	//seed random to current time
	cout << "Welcome to the Hotel Room Treasure Chest!\n";
	do{	//ensure user enters a chest of valid rows
		cout << "Enter number of rows: ";
		cin >> row;
		if(row < 1)	//prompts if row is invalid & loop after
			cout << "Number of rows has to be more than 1!\n";
	}while(row < 1);
	do{	//ensure user enters a chest of valid columns
		cout << "Enter number of columns: ";
		cin >> col;
		if(col < 1)	//prompts if column is invalid & loop after
			cout << "Number of columns has to be more than 1!\n";
	}while(col < 1);
	room **chest = new room*[row];	//pointers to pointers of each row
	for(int i = 0; i < row; i++)
		chest[i] = new room[col];	//array for each row

	while(true){
		/*in chance in every location that their whole chest might get lost*/
		if(rand()%(row*col) == 1){
			cout << "You lost your box!\n";
			clear_key(chest, row, col, value);
		}
		for(int i = row - 1; i >= 0; i--){
			cout << i + 1 << "\t|";	//display number for rows
			for(int j = 0; j < col; j++){
				if(chest[i][j].name.empty())
					cout << "_|";	//if empty print empty
				else	//not empty
					cout << chest[i][j].name[0] << "|";	//print first char of name
			}
			cout << endl;
		}

		cout << "Total value: " << value;	//display the total value
		cout << "\n1) Add room key\n2) Remove key\n3) Add random keys\n4) Show "
			"key\n5) Economic shift\n6) Edit\n7) Quit\nPlease make your choice: ";
		cin >> menu;	//gets the input that user wants to perform
		switch(menu){
			case 1:
				add_key(chest, row, col, value);
				break;
			case 2:
				remove_key(chest, row, col, value);
				break;
			case 3: 
				random_key(chest, row, col, value);
				break;
			case 4:
				show_key(chest, row, col, value);
				break;
			case 5:
				d_shift(chest, row, col, value);
				break;
			case 6:
				rename(chest, row, col, value);
				break;
			case 7:
				for(int i = 0; i < row; i++)
					delete [] chest[i];	//delete all columns of each row
				delete []chest;	//delete all pointers to each row
				return 0;	//end program
			default:	//if user  doesnt enter a valid operation
				cout << "Please only enter an integer value from 0 to 6.\n";
		}
	}
}

