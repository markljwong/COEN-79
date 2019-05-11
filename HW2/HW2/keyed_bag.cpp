#include "keyed_bag.h"
#include <stdio.h>
#include <cassert>
#include <cstdlib>

keyed_bag::keyed_bag() {
	size = 0;
}

//Insert an item at end of the set
void keyed_bag::insert(value_type new_data, int key) {
	assert(get_size() < CAPACITY);

	data[get_size()] = new_data;
	keys[get_size()] = key;

	size++;
}

bool keyed_bag::erase(int key) {
	//Attempt to find the given value, and shift values after it if found
	bool found = false;
	for (size_type i = 0; i < get_size(); i++) {
		if (found == true) {
			data[i - 1] = data[i];
			keys[i - 1] = keys[i];
		}
		if (keys[i] == key && found == false) {
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

//Returns size of set
keyed_bag::size_type keyed_bag::get_size() const {
	return size;
}

//Determines if set contains given value
bool keyed_bag::contains(int key) const {
	for (size_type i = 0; i < get_size(); i++) {
		if (keys[i] == key) {
			return true;
		}
	}
	return false;
}