#ifndef KEYED_BAG_H
#define KEYED_BAG_H

#include <iostream>

class keyed_bag {
public:
	// TYPEDEF and MEMBER CONSTANTS
	typedef double value_type;
	typedef std::size_t size_type;
	static const size_type CAPACITY = 30;

	//Constructors
	keyed_bag();

	//Setters
	void insert(value_type, int);
	bool erase(int);

	//Getters
	size_type get_size() const;
	bool contains(int) const;

private:
	size_type size;
	value_type data[CAPACITY];
	int keys[CAPACITY];
};

#endif
