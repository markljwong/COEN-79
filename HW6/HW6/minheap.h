#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>

using namespace std;

class minheap {
public:
	//Typedefs
	typedef int value_type;
	typedef size_t size_type;
	static const size_type CAPACITY = 16;

	//Constructors
	minheap();

	//Mutators
	void push(const value_type&);
	value_type pop();
	void swap(size_type, size_type);

	//Accessors
	int compare(size_type, size_type) const;
	size_type get_size() const;
	size_type get_max_size() const;

private:
	size_type size;
	size_type place;
	value_type data[CAPACITY];
	int order[CAPACITY];
};

#endif
