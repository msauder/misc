// alg_analysis.cpp
// Determine runtime of a provided algorithm given specific inputs
// Written by Matthew Sauder

#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

// Use nested for-loop to compute a summation
long long assignment1Algorithm(long long n);

int main() {
	clock_t  start; 
	clock_t  finish;
	long     long result;
	long     long n;
	long     double timeUsed;
	bool     continueQ = false;
	char     c; // placeholder char
	ofstream outfile("A1output.csv");

	// Initialize output CSV file with appropriate headings
	outfile << "\"result\",\"n/result\",\"n*log2(n)/result\",\"n^(3/2)/result\",\"timeUsed\",\"n/timeUsed\",\"n*log2(n)/timeUsed\",\"n^(3/2)/timeUsed\"" << endl;

	do {
		// Prompt user for an integer to perform the sum on
		cout << "Enter an integer: ";
		cin >> n;

		// Determine runtime by measuring clock cycles between starting and ending the algorithm and then dividing by the # of clocks per second
		start    = clock();
		result   = assignment1Algorithm(n);
		finish   = clock();
		timeUsed = ((long double)(finish - start))/CLOCKS_PER_SEC;

		// Output results to screen
		cout << "result               = " << result << endl;
		cout << "n/result             = " << ((float)n)/result << endl;
		cout << "n*log2(n)/result     = " << n*log(n)/log(2)/result << endl;
		cout << "pow(n, 1.5)/result   = " << pow(n, 1.5)/result << endl;
		cout << "timeUsed             = " << timeUsed << endl;
		cout << "n/timeUsed           = " << n/timeUsed << endl;
		cout << "n*log2(n)/timeUsed   = " << n*log(n)/timeUsed/log(2) << endl;
		cout << "pow(n, 1.5)/timeUsed = " << pow(n, 1.5)/timeUsed << endl;
		
		// Output results into a CSV file (for analysis later)
		outfile << result << ",";
		outfile << ((float)n)/result << ",";
		outfile << n*log(n)/log(2)/result << ",";
		outfile << pow(n, 1.5)/result << ",";
		outfile << timeUsed << ",";
		outfile << n/timeUsed << ",";
		outfile << n*log(n)/(timeUsed*log(2)) << ",";
		outfile << pow(n, 1.5)/timeUsed << endl;

		cout << "Would you like to continue (Y/N)? ";
		cin >> c;

		// Exit loop if user does not wish to continue
		if (c == 'y' || c == 'Y') {
			continueQ = true;
		}
		else continueQ = false;
	} while (continueQ);
	
	return 0;
}

// Use nested for-loop to compute a summation
// Pre: some number of steps to sum over is input by the user
// Post: summation is completed and returned by function
long long assignment1Algorithm(long long n) {
	long long sum = 0;
	for (long long i = 1; i <= n; i++) {
		for (long long j = n; j > 1; j = floor(j/2)) {
			sum += 1;
		}
	}
	return sum;
}