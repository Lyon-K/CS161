/**********************************************************
 * ** Program: 		lab9_recur.cpp
 * ** Author: 			Lyon Kee
 * ** Date: 			3/4/2020
 * ** Description: 	fibonacci iter and recur and compare time
 * ***********************************************************/

#include <iostream>
#include <sys/time.h>

using namespace std;

void elapsed_time(timeval start, timeval stop) {
	if (stop.tv_sec > start.tv_sec) 
		cout << "(seconds): " << stop.tv_sec-start.tv_sec << endl; 
	else 
		cout << "(microseconds): " << stop.tv_usec-start.tv_usec << endl; 
}

/* For non-negative n, compute and return the nth Fibonacci number. */
int fib_iter(int n) {
	int cur_fib = 0;  
	/* set up preceding Fibonacci numbers for n = 1 */
	int fib_minus_1 = 0; /* F0 = 0 */
	int fib_minus_2 = 1; /* F-1 doesn't exist but enables the loop */
	/* Loop from 1 to n; if n is 0, cur_fib is already set */
	for (int i=1; i<=n; i++) {
		cur_fib = fib_minus_1 + fib_minus_2;
		/* shift values */
		fib_minus_2 = fib_minus_1;
		fib_minus_1 = cur_fib;
	}
	return cur_fib;
}

/* Implement this function */
/* Assume n >= 0 */
int fib_recur(int n){
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return fib_recur(n-1) + fib_recur(n-2);
}

/* Implement this function */
/* Assume s >= 1 */
int n_ways_climb(int s){
	if(s==1)
		return 1;
	else if(s==2)
		return 2;
	else
		return n_ways_climb(s-1) + n_ways_climb(s-2);
}

int main()
{
	timeval stop, start;
	int usr;
	/* prompt user for a number to use */
	cin >> usr;
	gettimeofday(&start, NULL); 
	/* Call your iterative function here. */
	cout << "ITER RESULT:";
	cout << fib_iter(usr);
	gettimeofday(&stop, NULL); 
	cout << "Iterative runtime ";
	elapsed_time(start, stop);

	gettimeofday(&start, NULL); 
	/* Call your recursive function here. */
	cout << "RECUR RESULT:";
	cout << fib_recur(usr);
	gettimeofday(&stop, NULL); 
	cout << "Recursive runtime ";
	elapsed_time(start, stop);
	cout << endl << n_ways_climb(usr);
	return 0;
}
