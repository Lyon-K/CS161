/******************************************************************************
 ** Program: text_adventurer.cpp
 ** Author: Lyon Kee
 ** Date: 25/1/2020
 ** Description: Text adventurer game in a forest to save a princess
 ** Input: 3 whole numbered choices of different paths
 ** Output: Story line based on the inputs
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	/*
	 * Min: -1.2e38
	 * Max: 3.4e38
	 * justification: I needed it so that when the user enters a decimal it 
	 *		will be taken as an invalid input instead of multiple inputs
	 *		which is what usually happens when you try to enter decimals
	 *		in an int input. When that happens it will distrupt the flow
	 *		and disallow the user to enter into the next prompt.
	 */
	float choice, rerun = 1;
	/*
	 * Min: -2,147,483,648
	 * Max: 2,147,483,647
	 * justification: My maximum score range and roll range does not exceed
	 *		the range of int and is a whole number so it is chosen.
	 */
	int score, roll;
	cout << "\n\nGreetings!";
	srand(time(NULL));	//Seed the rand cursor according to time
	do{		//game starts here!
		score = 1;		//Set score to 1 to begin
		cout << "\n\n"
			"You are in an enchanted forest to save a princess in a castle!\n"
			"What kind of adventurer would you like to be?\n"
			"(1) Knight\n"
			"(2) Assassin\n"
			"(3) Geek\n"
			"Your choice: ";
		cin >> choice;
		if(choice == 1){					//Path 1
			cout << "\nYou are a knight! BE CHIVALROUS!\n"
				"(1) Take the road that leads straight to the castle!\n"
				"(2) Find a different path through the forest!\n";
			score *= 10;
			cin >> choice;
			if(choice == 1){				//Path 1.1
				cout << 
					"\nGood choice my knight!\nYou headed straight to the castle "
					"but bandits ambushed you on your way!\n"
					"Their health = 2\nRoll a die for your attack by entering a number: ";
				cin >> choice;
				roll = rand()%6 + 1;
				cout << "Your roll is: " << roll << endl;		//Random roll fight
				if(roll > 1){
					score *= 10;
					cout << "You won!\n"
						"\nYou reached the castle and found the princess on time!\n"
						"(1) Rush in to save the princess!\n"
						"(2) Survey the surrounding for enemies!\n";
					cin >> choice;
					if(choice == 1){		//Path 1.1.1
						score *= 10;
						cout << "\nA troll was about to hit the princess!\n"
							"You threw a dagger at him and decresed his heath "
							"by 4 when he is not looking!\n"
							"Their health = 3 \n"
							"Roll a die for your attack by entering a number: ";
						cin >> choice;
						roll = rand()%6 + 1;
						cout << "Your roll is: " << roll << endl;	//Random roll fight
						if(roll > 2){		//Winning path
							score *= 10;
							cout << "You beat the troll fair and square "
								"and stole the princess' heart aswell as her life!\n"
								"You beat the game! ";
						}
						else{
							cout << "You didn't kill him! He struck back and killed you!\n"
								"Good luck again next time\n";
						}
					}
					else if(choice == 2){	//Path 1.1.2
						cout << "You took too long and the princess was devoured "
							"by a troll!";
					}
					else
						cout << "Wrong choice buddy...\n";
				}
				else{
					cout << "You didn't kill him! He struck back and killed you!\n"
						"Good luck again next time\n";
				}
			}
			else if(choice == 2){			//Path 1.2
				cout << "You took the forest path and marched through swamps...\n"
					"When you got to the castle..\n"
					"You heard a loud bang, and when you looked for the room "
					"you see that a troll is eating her from the head down...\n"
					"ONLY IF YOU WERE A TINY BIT FASTER!\n";
			}
			else
				cout << "Wrong choice buddy...\n";
		}
		else if(choice == 2){				//Path 2
			cout << "\nYou are an assassin! BE CUNNING!\n"
				"(1) Take the road that leads straight to the castle!\n"
				"(2) Find a different path through the forest!\n";
			score *= 10;
			cin >> choice;
			if(choice == 1){				//Path 2.1
				cout << "\nAn assassin should be cunning and not proceed mindlessly!\n"
					"You got killed by a group of bandits!\n";
			}
			else if(choice == 2){			//Path 2.2
				cout << 
					"\nGood choice assassin!\nYou took a detour and avoided bandits"
					"but you met a witch which put a spell on you!\n"
					"roll anything but a 1 to be rid of the spell!\n"
					"Roll a die by entering a number: ";
				cin >> choice;
				roll = rand()%6 + 1;
				cout << "Your roll is: " << roll << endl;		//Random roll fight
				if(roll > 1){
					score *= 10;
					cout << "\nYou escaped!\n"
						"You rushed to the castle and found the princess ahead of time!\n"
						"(1) Rush in to save the princess!\n"
						"(2) Survey the surrounding for enemies!\n";
					cin >> choice;
					if(choice == 1){		//Path 2.2.1
						cout << "There was a troll in the room and he killed "
							"you in a long fight!\n";
					}
					else if(choice == 2){	//Path 2.2.2
						score *= 10;
						cout << "\nIn your survey of the room you found a troll!\n"
							"You sneaked up behind him!\n"
							"Your damage deals 3 times as much!\n"
							"Their health = 9 \n"
							"Roll a die for your attack by entering a number: ";
						cin >> choice;
						roll = rand()%6 + 1;
						cout << "Your roll is: " << roll << endl	//Random roll fight
							<< "Your attack is: " << roll*3 << endl;
						if(roll > 2){		//Winning path
							score *= 10;
							cout << "You beat the troll cunningly and saved the"
							" princess! Then you dessapeared like any other "
							"assassins... \nYOU BEAT THE GAME!\n";
						}
						else{
							cout << "You didn't kill him! He struck back and killed you!\n"
								"Good luck again next time\n";
						}
					}
					else
						cout << "Wrong choice buddy\n";
				}
				else
					cout << "You were not able to escape the spell....\n";
			}
			else
				cout << "Wrong choice buddy...\n";
		}
		else if(choice == 3)				//Path 3
			cout << "Geek is not an adventurer...\nYou got lost in the forest!\n";
		else								//Invalid path
			cout << "I dont get you...\n";
		cout << "Your score is " << score << endl;	//presents the score
		if(score == 1)
			cout << "Atleast you tried!\n";
		cout << "Do you want to play again (Enter 1 for yes)? \n";
		cin >> rerun;	//Asks if user wants to rerun
	}while(rerun == 1);	//Checks if user wants to rerun
	return 0;
}
