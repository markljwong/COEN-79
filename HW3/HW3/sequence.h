#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "node.h"
#include <iostream>

class sequence {
public:
	// TYPEDEF and MEMBER CONSTANTS
	typedef double value_type;
	typedef std::size_t size_type;

	//Constructors
	sequence();
	~sequence();

	//Setters
	void start();
	void end();
	value_type get_current() const;
	void advance();
	void retreat();

	void insert(value_type);
	void attach(value_type);
	void remove_current();
	void insert_front(value_type);
	void attach_back(value_type);
	void remove_front();

	//Getters
	bool is_item(node* n) const;
	size_type get_size() const;
	bool contains(value_type) const;
	value_type operator [](size_type index) const;

private:
	size_type size;
	node* head;
	node* tail;
	node* current;
};

#endif
