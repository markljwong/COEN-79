#ifndef SET_H
#define SET_H

#include "node.h"
#include <iostream>

using namespace std;

class set {
public:
	// TYPEDEF and MEMBER CONSTANTS
	typedef double value_type;
	typedef size_t size_type;

	//Constructors
	set();
	~set();

	//Setters
	void insert(value_type);
	bool erase(value_type);

	//Getters
	size_type get_size() const;
	bool contains(value_type) const;
	value_type operator [](size_type index) const;

private:
	size_type size;
	node* head;
	node* tail;
};

#endif
