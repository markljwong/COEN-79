#ifndef SET_H
#define SET_H

#include <iostream>

class set {
public:
	// TYPEDEF and MEMBER CONSTANTS
	typedef double value_type;
	typedef std::size_t size_type;
	static const size_type CAPACITY = 30;

	//Constructors
	set();

	//Setters
	void insert(value_type);
	bool erase(const value_type&);
	void operator -=(const set&);

	//Getters
	size_type get_size() const;
	bool contains(value_type) const;
	value_type operator [](size_type index) const;

private:
	size_type size;
	value_type data[CAPACITY];
};

#endif
