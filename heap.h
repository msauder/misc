// Heap.h
// Heap class definition
// Written by Matthew Sauder

#ifndef HEAP_H
#define HEAP_H

template <typename type> 
class Heap {
private:
  type *arrayPtr;
	int maxSize;
	int size;
public:
	Heap(int max);
	Heap(type array[], int size, int max);
	~Heap(); 

	void percolateUp(int i);
	void percolateDown(int i);
	void insert(type element);
	type remove();
	type findMax();
	bool isEmpty();
  void print();
	type operator[](int i);
};

// Heap.cpp
// Heap class implementation
// Written by Matthew Sauder

#include "Heap.h"
#include <iostream>
#include <iomanip>
using namespace std;

template <typename type>
Heap<type>::Heap(int max) {
	arrayPtr = new type[max];
	size = 0;
	maxSize = max;
}

template <typename type>
void Heap<type>::percolateDown(int i) {
	type temp;
    type parent = arrayPtr[i];
    type left = arrayPtr[2*i + 1];
    type right = arrayPtr[2*i + 2];
	while (i < size && (parent > left || parent > right)) {
		if (left > right) {
			temp = right;
			arrayPtr[2*i + 2] = arrayPtr[i];
			arrayPtr[i] = temp;
            i = 2*i + 2;
		}
		else if (left < right) {
			temp = left;
			arrayPtr[2*i + 1] = arrayPtr[i];
			arrayPtr[i] = temp;
            i = 2*i + 1;
		}
        parent = arrayPtr[i];
        left = arrayPtr[2*i + 1];
        right = arrayPtr[2*i + 2];
	}
}

template <typename type>
Heap<type>::Heap(type array[], int s, int max) {
	arrayPtr = array;
  size = s;
	maxSize = max;
	for (int i = size/2; i >= 0; i--) {
	  percolateDown(i);
	}
}

template <typename type>
void Heap<type>::percolateUp(int i) {
	type temp;
	while (i != 0 && arrayPtr[i] < arrayPtr[i/2]) {
		temp = arrayPtr[i];
		arrayPtr[i] = arrayPtr[i/2];
		arrayPtr[i/2] = temp;
		i = i/2;
	}
}

// Insert element into complete BT
template <typename type>
void Heap<type>::insert(type element) {
	if (size == maxSize) {
		cerr << "Cannot insert into heap. Heap is full." << endl;
		return;
	}
	int i = size;
	type temp;
	arrayPtr[i] = element;
	percolateUp(i);
}

template <typename type>
type Heap<type>::remove() {
	type temp;
	if (size == 0) {
		cerr << "Cannot remove from heap. Heap is empty." << endl;
		return;
	}
	temp = arrayPtr[0];
	arrayPtr[0] = arrayPtr[size - 1]; // Root node is replaced with final leaf
	percolateDown(0);
	return temp;
}

template <typename type>
type Heap<type>::findMax() {
	if (size == 0) {
		cerr << "Cannot find max of heap. Heap is empty" << endl;
		exit(1);
	}
	type temp = arrayPtr[0];
	for (int i = 1; i < size; i++) {
		if (temp < arrayPtr[i]) {
			temp = arrayPtr[i];
		}
	}
	return temp;
}

template <typename type>
bool Heap<type>::isEmpty() {
	return size == 0;
}

template <typename type>
void Heap<type>::print() {
    cout << setw(10) << "parent" << setw(10) << "left" << setw(10) << "right" << endl;
    for (int i = 0; i < size/2; i++) {
        cout << setw(10) << arrayPtr[i] << setw(10) << arrayPtr[2*i + 1] << setw(10) << arrayPtr[2*i + 2] << endl;
    }
    for (int i = 0; i < size; i++) {
        cout << arrayPtr[i] << " ";
    }
    cout << endl << endl;
}

template <typename type>
Heap<type>::~Heap() {
	size = 0;
	maxSize = 0;
	*arrayPtr = NULL;
}

template <typename type>
type Heap<type>::operator[](int i) {
	return arrayPtr[i];
}

#endif // HEAP_H
