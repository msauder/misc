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