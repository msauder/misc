// shellsort.cpp
// Check number of comparisons between shell sort using Hibbard gap sequence and one of my own creation
// Written by Matthew Sauder

#include <iostream>
using namespace std;

// Gap sequences for Hibbard and modified Fibonacci
int hibbard[9] = {1,3,7,15,31,63,127,255,511};
int modifiedFib[8] = {1,3,8,21,55,144,377,987}; // Fibonacci sequence with every other element removed
int comparisons = 0;

// Create duplicate free array with shuffled entries
void randomArray (int [], const int);

// Initialize array
void initArray (int [], const int);

// Shell sort using Hibbard gap sequence
void shellSortHibbard (int [], const int);

// SHell sort using modified Fibonacci gap sequence
void shellSortFib (int [], const int);

void print (int [], const int);
void copyArray (const int [], int [], const int);

int main () {
	int large[10], dupelarge[10];
	int larger[100], dupelarger[100];
	int largest[1000], dupelargest[1000];

	randomArray(large, 10); // Generate random array
	cout << "Initially random array: ";
	print(large, 10); // Print array to screen
	copyArray(large, dupelarge, 10); // Copy array for use by shellSortFib
	shellSortFib(dupelarge, 10);
	cout << "Modified Fibonacci sorted array: ";
	print(dupelarge, 10); // Print sorted array
	cout << "# of comparisons, modified Fibonacci: " << comparisons << endl; 
	comparisons = 0;
	shellSortHibbard(large, 10);
	cout << "Hibbard sorted array: ";
	print(large, 10);
	cout << "# of comparisons, Hibbard: " << comparisons << endl; 
	comparisons = 0;

	randomArray(larger, 100);
	copyArray(larger, dupelarger, 100);
	shellSortFib(dupelarger, 100);
	cout << "# of comparisons, modified Fibonacci: " << comparisons << endl; 
	comparisons = 0;
	shellSortHibbard(larger, 100);
	cout << "# of comparisons, Hibbard: " << comparisons << endl; 
	comparisons = 0;

	randomArray(largest, 1000);
	copyArray(largest, dupelargest, 1000);
	shellSortFib(dupelargest, 1000);
	cout << "# of comparisons, modified Fibonacci: " << comparisons << endl; 
	comparisons = 0;
	shellSortHibbard(largest, 1000);
	cout << "# of comparisons, Hibbard: " << comparisons << endl; 
	comparisons = 0;

	return 0;
}

// Initialize array
// Pre: an array and its size are provided
// Post: array has been initialized so a[i] = i and returned by reference
void initArray (int array[], const int size) {
	for (int i = 0; i < size; i++) {
		array[i] = i;
	}
}

// Create duplicate free array with shuffled entries
// Pre: an array and its size are provided
// Post: arrays contents are shuffled and returned by reference
void randomArray (int array[], const int size) {
	initArray(array, size);
	for (int i = size-1; i > -1; i--) {
		int rng = rand() % (i + 1);
		int temp = array[rng];
		array[rng] = array[i];
		array[i] = temp;
	}
}

// Shell sort using Hibbard gap sequence
// Pre: a randomized array and its size are provided
// Post: arrays contents are sorted and returned by reference
void shellSortHibbard (int array[], const int size) {
	int gap, startGap, temp, tempi;
	// Determine how many gap sizes need to be used
	switch (size) {
		case 10: startGap = 2;
		case 100: startGap = 5;
		case 1000: startGap = 8;
	}
	// Loop through gap sizes starting with largest relevant gap size
	for (int k = startGap; k > -1; k--) {
		gap = hibbard[k];
		// Go through array, doing insertion sort for each element using gap sequence
		for (int i = gap; i < size; i++) {
			temp = array[i];
			tempi = i;
			// Insertion sort loop for a given element
			while (tempi >= gap && array[tempi - gap] > temp) {
				array[tempi] = array[tempi - gap];
				tempi = tempi - gap;
				comparisons++;
			}
			array[tempi] = temp;
		}
	}
}

// Shell sort using modified Fibonacci gap sequence
// Pre: a randomized array and its size are provided
// Post: arrays contents are sorted and returned by reference
void shellSortFib (int array[], const int size) {
	int gap, startGap, temp, tempi;
	switch (size) {
		case 10: startGap = 2;
		case 100: startGap = 4;
		case 1000: startGap = 8;
	}
	// Loop through gap sizes starting with largest relevant gap size
	for (int k = startGap; k > -1; k--) {
		gap = modifiedFib[k];
		// Go through array, doing insertion sort for each element using gap sequence
		for (int i = gap; i < size; i++) {
			temp = array[i];
			tempi = i;
			// Insertion sort loop for a given element
			while (tempi >= gap && array[tempi - gap] > temp) {
				array[tempi] = array[tempi - gap];
				tempi = tempi - gap;
				comparisons++;
			}
			array[tempi] = temp;
		}
	}
}

void print (int array[], const int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void copyArray (const int array1[], int array2[], const int size) {
	for (int i = 0; i < size; i++) {
		array2[i] = array1[i];
	}
}