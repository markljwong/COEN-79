#include "bag.h"
#include "node.h"
#include <iostream>

using namespace std;

//Constructor
bag::bag() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

//Destructor
bag::~bag() {
	node* cursor = head;
	node* temp = nullptr;
	while (cursor != nullptr) {
		temp = cursor;
		cursor = cursor->get_next();
		delete(temp);
	}
}

//Insert new_data into bag
void bag::insert(value_type new_data) {
	if (get_size() == 0) {
		head = tail = new node(new_data, nullptr, nullptr);
	}
	else {
		tail->set_next(new node(new_data, nullptr, tail));
		tail = tail->get_next();
	}
	size++;
}

bag::size_type bag::remove_reps() {
	int removed_count = 0;

	node* cursor = head;
	node* cursor2 = cursor->get_next();
	node* temp = nullptr;

	//If not empty list, iterate through linked list and remove each elements duplicates
	if (get_size() != 0) {
		while (cursor != nullptr) {

			//Loop through rest of array checking using cursor2 and checking it against cursor
			//To see if it should be removed
			cursor2 = cursor->get_next();
			while (cursor2 != nullptr) {
				if (cursor2->get_data() == cursor->get_data()) {
					if (get_size() == 1) {
						temp = head;
						head = nullptr;
						tail = nullptr;
					}
					else if (cursor2 == head) {
						temp = head;
						head = head->get_next();
						head->set_prev(nullptr);
					}
					else if (cursor2 == tail) {
						temp = tail;
						tail = tail->get_prev();
						tail->set_next(nullptr);
					}
					else {
						temp = cursor2;
						cursor2->get_prev()->set_next(cursor2->get_next());
						cursor2->get_next()->set_prev(cursor2->get_prev());
					}

					//Reset cursor then delete temp and update values
					cursor2 = cursor2->get_prev();
					delete(temp);
					size--;
					removed_count++;
				}
				cursor2 = cursor2->get_next();
			}
			cursor = cursor->get_next();
		}
	}
	return removed_count;
}

void bag::reverse() { 
	node* cursor = head;
	node* temp = cursor;

	//If no elements or only one element just return. Reverse is the exact same.
	if (size == 0 || size == 1) {
		return;
	}

	//Swap each element's next and prev nodes
	while (cursor != nullptr) {
		temp = cursor->get_next();
		cursor->set_next(cursor->get_prev());
		cursor->set_prev(temp);

		cursor = cursor->get_prev();
	}
	
	//Update head and tail pointers
	temp = head;
	head = tail;
	tail = temp;
}

bag::size_type bag::get_count(const value_type& value) const {
	size_type count = 0;
	node* cursor = head;

	while (cursor != nullptr) {
		if (cursor->get_data() == value) count++;
		cursor = cursor->get_next();
	}

	return count;
}

void bag::print_list() const {
	node* cursor = head;
	size_type index = 0;

	while (cursor != nullptr) {
		cout << "Value at position " << index << ": " << cursor->get_data() << endl;

		index++;
		cursor = cursor->get_next();
	}

	cout << endl;
}