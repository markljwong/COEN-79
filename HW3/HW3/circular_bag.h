#pragma once
#ifndef CIRCULAR_BAG_H
#define CIRCULAR_BAG_H

#include "node.h"

class circular_bag {
public:
	typedef double value_type;
	typedef size_t size_type;

	//Constructors and Destructors
	circular_bag();
	~circular_bag();

	//Mutators
	void insert(value_type);
	size_type remove_reps();
	void reverse();

	//Accessors
	size_type get_size() const { return size; }
	size_type get_count(const value_type&) const;
	void print_list() const;

private:
	node* head;
	node* tail;
	size_type size;
};

#endif