#include "set.h"
#include <cassert>

set::set() {
	size = 0;

	head = nullptr;
	tail = nullptr;
}

set::~set() {
	node* cursor = head;

	node* temp = nullptr;

	while (cursor != nullptr) {
		temp = cursor;
		cursor = cursor->get_next();
		delete(temp);
	}
}

//Insert an item at end of the set
void set::insert(value_type new_data) {
	//Don't add the new_data if it already exists
	if (contains(new_data)) return;

	if (get_size() == 0) {
		head = tail = new node(new_data, nullptr, nullptr);
	}
	else {
		tail->set_next(new node(new_data, nullptr, tail));
		tail = tail->get_next();
	}

	size++;
}

bool set::erase(value_type value) {
	node* cursor = head;
	node* temp = nullptr;

	//Attempt to find the value and remove accordingly
	while (cursor != nullptr) {
		if (cursor->get_data() == value) {
			if (size == 1) {
				temp = head;
				head = nullptr;
				tail = nullptr;
			}
			else if (cursor == head) {
				temp = head;
				head = head->get_next();
				head->set_prev(nullptr);
			}
			else if (cursor == tail) {
				temp = tail;
				tail = tail->get_prev();
				tail->set_next(nullptr);
			}
			else {
				temp = cursor;
				cursor->get_prev()->set_next(cursor->get_next());
				cursor->get_next()->set_prev(cursor->get_prev());
			}

			delete(temp);
			size--;

			return true;
		}
		cursor = cursor->get_next();
	}

	//If function reaches here, it isn't found or empty list
	return false;
}

//Returns size of set
set::size_type set::get_size() const {
	return size;
}

//Determines if set contains given value
bool set::contains(value_type value) const {
	node* cursor = head;

	while (cursor != nullptr) {
		if (cursor->get_data() == value) return true;
		cursor = cursor->get_next();
	}

	//If function reaches here, it isn't found
	return false;
}

//Subscript operator to get values at index position
//Returns -1 if out of range
set::value_type set::operator [](size_type index) const {
	//Make sure the index is within size of linked list
	if (index >= size) return -1;

	size_type counter = 0;
	node* cursor = head;

	while (cursor != nullptr && counter != index) {
		cursor = cursor->get_next();
		counter++;
	}

	return cursor->get_data();
}