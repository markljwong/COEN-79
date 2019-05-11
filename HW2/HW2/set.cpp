#include "set.h"
#include <stdio.h>
#include <cassert>

set::set() {
	size = 0;
}

//Insert an item at end of the set
void set::insert(value_type new_data) {
	//Only add data if there is free capacity and there is no duplicate
	assert(get_size() < CAPACITY);
	assert(contains(new_data) == false);

	data[get_size()] = new_data;
	size++;
}

bool set::erase(const value_type& value) {
	//Attempt to find the given value, and shift values after it if found
	bool found = false;
	for (size_type i = 0; i < get_size(); i++) {
		if (found == true) {
			data[i - 1] = data[i];
		}
		if (data[i] == value && found == false) {
			found = true;
		}
	}

	//Update size only if found and return true
	if (found == true) {
		size--;
		return true;
	}

	//Return false if not found
	return false;
}

//Operator for subtracting set from a set
void set::operator -=(const set& RHS) {
	for (size_type i = 0; i < RHS.get_size(); i++) {
		erase(RHS[i]);
	}
}


//Returns size of set
set::size_type set::get_size() const {
	return size;
}

//Determines if set contains given value
bool set::contains(value_type value) const {
	for (size_type i = 0; i < get_size(); i++) {
		if (data[i] == value) {
			return true;
		}
	}
	return false;
}

//Subscript operator to get values in the set's array
set::value_type set::operator [](size_type index) const {
	return data[index];
}