#include "dynamic_set.h"
#include <stdio.h>
#include <cassert>

dynamic_set::dynamic_set() {
	size = 0;
	max_size = INIT_CAPACITY;
}

//Insert an item at end of the set
void dynamic_set::insert(value_type new_data) {
	//Only add data if there is no duplicate
	assert(contains(new_data) == false);

	//Create a new array with more capacity if array already filled
	if (get_size() >= max_size) {
		value_type* temp = new value_type[get_size() + max_size];
		for (size_type i = 0; i < get_size(); i++) {
			temp[i] = data[i];
		}
		*data = *temp;
		max_size += max_size;
	}

	data[get_size()] = new_data;
	size++;
}

bool dynamic_set::erase(const value_type & value) {
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
void dynamic_set::operator -=(const dynamic_set& RHS) {
	for (size_type i = 0; i < RHS.get_size(); i++) {
		erase(RHS[i]);
	}
}


//Returns size of set
dynamic_set::size_type dynamic_set::get_size() const {
	return size;
}

//Returns max size of set
dynamic_set::size_type dynamic_set::get_max_size() const {
	return max_size;
}

//Determines if set contains given value
bool dynamic_set::contains(value_type value) const {
	for (size_type i = 0; i < get_size(); i++) {
		if (data[i] == value) {
			return true;
		}
	}
	return false;
}

//Subscript operator to get values in the set's array
dynamic_set::value_type dynamic_set::operator [](size_type index) const {
	return data[index];
}