/*
 *  * Starter code for assignment 6
 *   * Recursion with structs: trains
 *    * Author: your_name_here + Kiri Wagstaff
 *     * Due: March 14, 2020
 *      */
#include <iostream>
#include <cstdlib>

using namespace std;

struct train_car {
	string kind;
	train_car* next_car;
	int seats, seated;
};

/* Recursively add n_cars new train cars to train t */
/* Assume n_cars > 0 */
void add_cars(train_car* t, int n_cars) {
	/* Add another train car */
	t->next_car = new train_car;
	t->next_car->next_car = NULL; /* be safe! */

	if (n_cars == 1) { /* base case: caboose */
		t->next_car->kind = "Caboose";
		t->next_car->seats = 0;
		t->next_car->seated = 0;
	} else {
		t->next_car->kind = "_***_";
		add_cars(t->next_car, n_cars-1); /* recursive call */
		t->next_car->seats = rand()%11 + 10;
		t->next_car->seated = 0;
	}
}

/* Recursively print the train, one car at a time */
void print_train(train_car* t) {
	/* Print this car */
	cout << "(" << t->seated << "/" << t->seats << ")";
	cout << t->kind; 
	if (t->kind == "Caboose")   /* base case */
		cout << "\n";
	else
		print_train(t->next_car); /* recursive step */
}

/* Recursively delete the memory for this train */
void delete_train(train_car* t) {
	if (t->kind == "Caboose")   /* base case */
		delete t;
	else {
		/* Delete the rest of the train first */
		delete_train(t->next_car);  /* recursive step */
		/* Now delete this car */
		delete t;
		/* Why will it not work to delete t, 
		 *      * then make the recursive call? */
	}
}

int length_car(train_car *t){
	if(t->kind == "Caboose")
		return 1;
	else 
		return 1 + length_car(t->next_car);
}

int fill(train_car *t, int ppl){
	if(ppl <= 0)
		return 0;
	else if(t->kind == "Caboose")
		return ppl;
	else if(t->seats > t->seated){
		t->seated += 1;
		return fill(t, ppl - 1);
	} else {
		return fill(t->next_car, ppl);
	}
}

int main() {
	srand(time(NULL));

	/* Create my train */
	train_car* my_train0 = new train_car;
	my_train0->kind = "Engine";
	my_train0->next_car = NULL; /* be safe! */
	my_train0->seats = 0;
	my_train0->seated = 0;

	train_car* my_train1 = new train_car;
	my_train1->kind = "Engine";
	my_train1->next_car = NULL; /* be safe! */
	my_train1->seats = 0;
	my_train1->seated = 0;

	train_car* my_train2 = new train_car;
	my_train2->kind = "Engine";
	my_train2->next_car = NULL; /* be safe! */
	my_train2->seats = 0;
	my_train2->seated = 0;

	train_car* my_train3 = new train_car;
	my_train3->kind = "Engine";
	my_train3->next_car = NULL; /* be safe! */
	my_train3->seats = 0;
	my_train3->seated = 0;

	train_car* my_train4 = new train_car;
	my_train4->kind = "Engine";
	my_train4->next_car = NULL; /* be safe! */
	my_train4->seats = 0;
	my_train4->seated = 0;

	train_car* my_train5 = new train_car;
	my_train5->kind = "Engine";
	my_train5->next_car = NULL; /* be safe! */
	my_train5->seats = 0;
	my_train5->seated = 0;

	int n_cars = rand()%10 + 1; /* number of cars to add: 1 to 10 */
	add_cars(my_train0, n_cars);

	n_cars = rand()%5 + 1; /* number of cars to add: 1 to 10 */
	add_cars(my_train1, n_cars);


	n_cars = rand()%5 + 1; /* number of cars to add: 1 to 10 */
	add_cars(my_train2, n_cars);


	n_cars = rand()%5 + 1; /* number of cars to add: 1 to 10 */
	add_cars(my_train3, n_cars);


	n_cars = rand()%5 + 1; /* number of cars to add: 1 to 10 */
	add_cars(my_train4, n_cars);


	n_cars = rand()%5 + 1; /* number of cars to add: 1 to 10 */
	add_cars(my_train5, n_cars);

	int n;

	cout << "The journey begins, usig train 0!\n";
	for(int i = 1; i <= 5; i++){
		print_train(my_train0);		
		cout << "\nStation " << i << ": How many new passengers? ";
		cin >> n;
		cout << "Seated all but " << fill(my_train0, n) 
			<< " passengers from station " << i << ".\n";
	}
	delete_train(my_train0);

	cout << "The journey begins, usig train 1!\n";
	for(int i = 1; i <= 5; i++){
		print_train(my_train1);		
		cout << "\nStation " << i << ": How many new passengers? ";
		cin >> n;
		cout << "Seated all but " << fill(my_train1, n) 
			<< " passengers from station " << i << ".\n";
	}
	delete_train(my_train1);

	cout << "The journey begins, usig train 2!\n";
	for(int i = 1; i <= 5; i++){
		print_train(my_train2);
		cout << "\nStation " << i << ": How many new passengers? ";
		cin >> n;
		cout << "Seated all but " << fill(my_train2, n) 
			<< " passengers from station " << i << ".\n";
	}
	delete_train(my_train2);

	cout << "The journey begins, usig train 3!\n";
	for(int i = 1; i <= 5; i++){
		print_train(my_train3);
		cout << "\nStation " << i << ": How many new passengers? ";
		cin >> n;
		cout << "Seated all but " << fill(my_train3, n) 
			<< " passengers from station " << i << ".\n";
	}
	delete_train(my_train3);

	cout << "The journey begins, usig train 4!\n";
	for(int i = 1; i <= 5; i++){
		print_train(my_train4);
		cout << "\nStation " << i << ": How many new passengers? ";
		cin >> n;
		cout << "Seated all but " << fill(my_train4, n) 
			<< " passengers from station " << i << ".\n";
	}
	delete_train(my_train4);

	cout << "The journey begins, usig train 5!\n";
	for(int i = 1; i <= 5; i++){
		print_train(my_train5);
		cout << "\nStation " << i << ": How many new passengers? ";
		cin >> n;
		cout << "Seated all but " << fill(my_train5, n) 
			<< " passengers from station " << i << ".\n";
	}
	delete_train(my_train5);

	return 0;
}

