#ifndef KEYED_BAG_H
#define KEYED_BAG_H

#include "node.h"
#include <iostream>

class keyed_bag {
public:
	// TYPEDEF and MEMBER CONSTANTS
	typedef double value_type;
	typedef std::size_t size_type;

	//Constructors
	keyed_bag();
	~keyed_bag();

	//Setters
	void insert(value_type, value_type);
	bool erase(value_type);

	//Getters
	size_type get_size() const;
	bool contains(value_type) const;

private:
	size_type size;

	node* data_head;
	node* data_tail;

	node* keys_head;
	node* keys_tail;
};

#endif
