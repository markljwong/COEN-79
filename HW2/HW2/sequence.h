#ifndef COEN79_SEQUENCE1_H
#define COEN79_SEQUENCE1_H

#include <iostream>
    
class sequence {
public:
	// TYPEDEF and MEMBER CONSTANTS
	typedef double value_type;
	typedef std::size_t size_type;
	static const size_type CAPACITY = 30;
        
	//Constructors
	sequence() {
		used = 0;
		current_index = 0;
	}
        
	//Setters
	void start();
	void end();
	void last();
	value_type current() const;
	void advance();
	void retreat();
        
	void insert(value_type);
	void attach(value_type);
	void remove_current();
	void insert_front(value_type);
	void attach_back(value_type);
	void remove_front();
	void operator +=(const sequence &RHS);

	//Getters
	size_type size() const;
	bool is_item() const;
	value_type operator [](size_type index) const;
        
	double mean() const;
	double standardDeviation() const;

private:
	size_type used;
	value_type data[CAPACITY];
	size_type current_index;
};
    
sequence::value_type summation(const sequence &s);
sequence operator +(const sequence &LHS, const sequence &RHS);

#endif
