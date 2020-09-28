/*****************************************************
 ** Program: fortune_teller.cpp 
 ** Author: Lyon Kee
 ** Date: 10/1/20
 ** Description: Assignment 1(CS161)
 ** Input:  5 numbers
 ** Output: 3 fortunes
 ******************************************************/
#include <iostream>

int main(){
/*
 * Min:-2,147,483,648 
 * Max:2,147,483,647
 * This is chosen as an array is would usually 
 * not exceed this limit but will exceed a short.
 */
	int array_index_range; 
/* 
 * Min: 0
 * Max: 18,446,744,073,709,551,615
 * time_to_solve_bugs and spin_mins is assigned long because time has no limit
 * and this is the largest data type available for int.
 */
	unsigned long time_to_solve_bugs, spin_mins;
/*
 * Min: 2.2e-308
 * Max: 1.8e308
 * This data type was assigned because time is indefinite and there is
 * time prior to and after the start of humanity.
 */
	double age_of_humanity;
/*
 * Min: 1.2e-38
 * max: 3.4e38
 * A person could spin any number of revolutions either positive(clock wise)
 * or negative(counter clockwise) revolutions and it is not possible to achieve
 * over the limit of this data type as a human being.
 */
	float number_of_revolutions;

//First fortune
	std::cout << "Please enter a whole number(negative prefered): " <<std::endl;
	std::cin >> array_index_range;
	std::cout << "Please enter a positive whole number: " <<std::endl;
	std::cin >> time_to_solve_bugs;
	std::cout<< std::endl << 
		"In the near future you will encounter an error that states index"
		" out of bounds exception. Index out of range: " << array_index_range
		<< "\nI couldn't solve it but you will solve it in just "
		<< time_to_solve_bugs << " seconds!.\n" << std::endl;

//Second fortune
	std::cout << "Please enter a number: " << std::endl;
	std::cin >> age_of_humanity;
	std::cout<< std::endl << 
		"You will wake up tomorrow with the humanity clock being " << 
		age_of_humanity << " hour(s) old!\nGood luck!!\n" << std::endl;

//Third fortune
	std::cout << "Please enter a positive whole number: " <<std::endl;
	std::cin >> spin_mins; 
	std::cout << "Please enter a number: " <<std::endl;
	std::cin >> number_of_revolutions;
	std::cout<< std::endl << "You have " << spin_mins << " minutes to spin " 
		<< number_of_revolutions << " revolutions.\nGO!!"<< std::endl;
}

