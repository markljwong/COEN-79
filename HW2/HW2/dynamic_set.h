#ifndef DYNAMIC_SET_H
#define DYNAMIC_SET_H

#include <iostream>

class dynamic_set {
public:
	// TYPEDEF and MEMBER CONSTANTS
	typedef double value_type;
	typedef std::size_t size_type;
	static const size_type INIT_CAPACITY = 4;

	//Constructors
	dynamic_set();

	//Setters
	void insert(value_type);
	bool erase(const value_type&);
	void operator -=(const dynamic_set&);

	//Getters
	size_type get_size() const;
	size_type get_max_size() const;
	bool contains(value_type) const;
	value_type operator [](size_type index) const;

private:
	size_type size;
	size_type max_size;
	value_type data[INIT_CAPACITY];
};

#endif
