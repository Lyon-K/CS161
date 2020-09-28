/*******************************************************************************
 * ** Program Filename:	assign3_flight.cpp
 * ** Author:				Lyon Kee
 * ** Date:					7/2/2020
 * ** Description:		animates a flight based on the user variable input
 * ** Input:				distance, airspeed, windspeed, gph, fuel_price, people
 * ** Output:				animation, duration, cost per person
 * ****************************************************************************/
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

/*******************************************************************************
 * ** Function:			flight_duration
 * ** Description:		calculates the duration of the flight
 * ** Parameters:			distance, airspeed, windspeed
 * ** Pre-Conditions:	airspeed > windspeed & distance > 0
 * ** Post-Conditions:	returns the duration of the flight
 * ****************************************************************************/
float flight_duration(float distance, float airspeed, float windspeed){
	/*
	 * Min: 1.2e-38
	 * Max: 3.4e38
	 * duration has decimal points for minutes and seconds.
	 */
	float duration = (distance / (airspeed - windspeed));
	return duration;
}

/*******************************************************************************
 * ** Function:			cost_per_pax
 * ** Description:		calculates cost per person to breakeven
 * ** Parameters:			duration, gph, price, people
 * ** Pre-Conditions:	gph, price per gallon, people > 0 with people as int
 * ** Post-Conditions:	returns the cost of the flight for one person
 * ****************************************************************************/
float cost_per_pax(float duration, float gph, float price, int people){
	return (duration * gph * price / people);
}

/*******************************************************************************
 * ** Function:			animation
 * ** Description:		display the animation of the flight depending on user
 * ** Parameters:			plane, duration, seconds, direction
 * ** Pre-Conditions:	plane orientation, default direction = left to right
 * ** Post-Conditions:	shows the animation of plane flying left or right
 * ****************************************************************************/
void animation(string plane, float duration, float seconds, int direction = 1){
	if(direction == 2){
		for(int lim = 74; lim >= 0; lim--){
			system("clear");
			for(int i = 0; i < 9; i++){
				for(int x = 73-(74-lim); x > 0; x--)
					cout << ' ' << flush;
				for(int p = 73; p >= lim; p--)
					cout << plane.at(p + 75*i)<<flush;
				cout << endl;
			}
			usleep(1000000/75*duration*seconds);
		}
	}
	else{
		for(int lim = 74; lim >= 0; lim--){
			system("clear");
			for(int i = 0; i < 9; i++)
				for(int p = lim; p <=74; p++)
					cout << plane.at(p+75*i);
			usleep(1000000/75*duration*seconds);
		}
	}
}

int main(){
	/*
	 * Min: 1.2e-38
	 * Max: 3.4e38
	 * The following variable has decimal points for precision.
	 */
	float distance, airspeed, windspeed, gph, fuel_price, seconds, duration;
	/*
	 * Min: 2147483647
	 * Max: -2147483648
	 * The following variable is only whole numbers but for ease of data type 
	 * an int is assigned, and it is regulated in error handling.
	 */
	int people;
	/*
	 * Min: NULL
	 * Max: -2^204
	 * The following variable is in string to represent an airplane.
	 */
	string plane =				//each row is 75 col so it exceeded for presentation 
		"                 __________                                               \n"
		"        _________\\_________\\_______                                       \n"
		":::::::(___________+___+___+_______)                                      \n"
		"                 __\\___\\__\\___________________________________________    \n"
		"        ......../            O O O O O O O O O O O O O O O O O O    /\\\\__ \n"
		"        ````````\\......................................................._)\n"
		"                  \\___________________________________________________/   \n"
		"                        \\_______________/--------------------------/      \n"
		"               ::::::::::::C__________D                                   \n";
	do{
		cout << 	"\nPlease provide the following flight information:\n"
					"1) Flight distance (miles): ";
		cin >> distance;								//user input distance
	}while(distance <= 0);							//checks if user input is valid
	do{
		cout << 	"\n2) Airplane airspeed (miles per hour): ";
		cin >> airspeed;
	}while(airspeed <= 0);                    //checks if user input is valid
	do{
		cout << 	"\n3) Wind speed (miles per hour)"
			"(cannot be equal or more than airspeed): ";
		cin >> windspeed;
	}while(windspeed >= airspeed);				//checks if user input is valid
	do{
		cout << 	"\n4) Fuel burn rate (gallons per hour): ";
		cin >> gph;
	}while(gph <= 0);									//checks if user input is valid
	do{
		cout << "\n5) Fuel price (dollars per gallon): ";	
		cin >> fuel_price;
	}while(fuel_price <= 0);						//checks if user input is valid
	do{
		cout << "\n6) Number of people onboard: ";
		cin >> people;
	}while(people <= 0);                    	//checks if user input is valid
	do{
		cout << "\n7) Seconds of animation per flight hour: ";
		cin >> seconds;
	}while(seconds <= 0);                    	//checks if user input is valid
	/* Assign duration because it is used a lot and I dont want the whole 
	 * function run everytime I want to use the value.
	 */
	duration = flight_duration(distance, airspeed, windspeed);
	animation(plane, duration, seconds);		//animates left to right flight
		cout << "Your flight took " << duration << " hours and " 
			<< (duration - (int) duration) * 60 << " minutes, and cost $" 
			<< cost_per_pax(duration, gph, fuel_price, people) 
			<< " per person. Going back in 5 seconds!\n";
	usleep(5000000);									//allow time for user to read
	/* Updates the duration because the wind speed now acts on the speed
	 * of the plane in the opposite axis.
	 */
	duration = flight_duration(distance, airspeed, -windspeed);
	/* Updates some of the character to allow the animation to be printed 
	 * backwards.
	 */
	for(int i = 0; i < 75*9; i++){
		switch(plane.at(i)){
			case '/':
				plane.at(i) = '\\';
				break;
			case '\\':
				plane.at(i) = '/';
				break;
			case '(':
				plane.at(i) = ')';
				break;
			case ')':
				plane.at(i) = '(';
				break;
			case 'D':
				plane.at(i) = 'C';
				break;
			case 'C':
				plane.at(i) = 'D';
				break;
		}
	}
	animation(plane, duration, seconds, 2);	//direction = 2 for right to left
	cout << "Your flight took " << duration << " hours and " 
		<< (duration - (int) duration) * 60 << " minutes, and cost $" 
		<< cost_per_pax(duration, gph, fuel_price, people) << " per person.\n";
	
	return 0;
}
