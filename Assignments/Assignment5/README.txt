Name: Lyon Kee
ONID: 934057854
Section: CS 161-020
Assignment 5, due 3/8/2020

Description:

Welcome to Hotel Room Treasure chest! You can insert your own hotel key
or you could generate them randomly, each item's value is stored in a total 
and displayed after the treasure chest display. There is a 
chance that all items might get lost deending on the size of the treasure chest.
Good luck on expanding your hotel colection!

Instructions:

1) Compile the program with

g++ assign5_treasure.cpp

2) Run the program with

./a.out

3) You start with by entering the size of the chest, there are no items
in the chest when you start. You will have a choice at the menu with a 
visual representation of the chest. The options include remove objects, 
showing the object, and generating attributes to an object, edit a key's 
attribute, as well as to randomize the economy and change the value of 
all items.

The menu option and representation at the start for a 5 x 5 chest
are as follow:
5       |_|_|_|_|_|
4       |_|_|_|_|_|
3       |_|_|_|_|_|
2       |_|_|_|_|_|
1       |_|_|_|_|_|
Total value: 0
1) Add room key
2) Remove key
3) Add random keys
4) Show key
5) Economic shift
6) Rename
7) Quit

If you chose to add a room, you are presented with the inputs:
Please make your choice: 
Enter row: 
Enter column: 
Enter a name for your room: 
Enter which floor the room Alpha exists on: 
Enter the number of beds in your room: 
Enter the cost of your room: 
Does your room have a tv?(0-no, 1-yes) 

If you chose to remove an item and the location is valid:
Enter row: 
Enter column: 
An item was removed from the location:
Row: 1
Column: 1

if the location is not then there will be an error prompt.

If you choose to generate a room key then it could look like the following:
Please make your choice: 3
Enter row: 1
Enter column: 1
Enter a name for the room you would like to generate: a
5       |_|_|_|_|_|
4       |_|_|_|_|_|
3       |_|_|_|_|_|
2       |_|_|_|_|_|
1       |a|_|_|_|_|
Total value: 354.62

If you choose to make an economic shift then it will look somwhat like
the following:
The economic shift made prices to shift -1.98% of their original price.
5       |_|_|_|_|_|
4       |_|_|_|_|_|
3       |_|_|_|_|_|
2       |_|_|_|_|_|
1       |a|_|_|_|_|
Total value: 347.599

Showing a room key would look something like the following:
Enter row: 1
Enter column: 1
Name: alpha
Floor: 172
Beds: 1 per night
Cost: 352.117
TV: included
5       |_|_|_|_|_|
4       |_|_|_|_|_|
3       |_|_|_|_|_|
2       |_|_|_|_|_|
1       |a|_|_|_|_|
Total value: 352.117

By chance, you might loose your box and it will look something like this:
You lost your box!
An item named 1 have been lost at the position:
Row: 1
Column: 1

3       |_|_|_|
2       |_|_|_|
1       |_|_|_|
Total value: 0

If you enter an invalid option you will be prompted, ont of it could be
in the main menu and it would look like the following:
1) Add room key
2) Remove key
3) Add random keys
4) Show key
5) Economic shift
6) Rename
7) Quit
Please make your choice: 7
Please only enter an integer value from 0 to 6.
3       |_|_|_|
2       |_|_|_|
1       |_|_|_|
Total value: 0
1) Add room key
2) Remove key
3) Add random keys
4) Show key
5) Economic shift
6) Rename
7) Quit

If the user chooses to edit, it might look something like this.

4) Limitations:
- If an key is deleted it is not recoverable.
- Because of the chance of loosing items, it is almost impossible to fully 
	fill up the chest.
- You cannot control the economic shift.
- you have to remove an item before adding it, replace is not allowed.
- You cannot have attributes that are unrealistic for the floor the
	room is on.
- There is no way to edit so you have to remove then add again.

5) Extra credit:
- This program contains a chance where it is 1 in the number of boxes the user 
declared in the begining of the program where the user might loose the 
treasure chest and the contents are all lost and they would have to start all 
over again with 0 items and 0 value, as all items are cleared.
