#include "circular_bag.h"
#include "node.h"
#include <iostream>

using namespace std;

//Constructor
circular_bag::circular_bag() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

//Destructor
circular_bag::~circular_bag() {
	size_type counter = 0;
	
	node* cursor = head;
	node* temp = nullptr;

	while (counter < get_size()) {
		temp = cursor;
		cursor = cursor->get_next();
		delete(temp);

		counter++;
	}
}

//Insert new_data into bag
void circular_bag::insert(value_type new_data) {
	node* new_node = new node(new_data, nullptr, nullptr);

	if (get_size() == 0) {
		head = new_node;
		head->set_next(head);
		head->set_prev(head);
		tail = head;
	}
	else {
		new_node->set_next(head);
		new_node->set_prev(tail);
		head->set_prev(new_node);
		tail->set_next(new_node);
		tail = new_node;
	}
	size++;
}

circular_bag::size_type circular_bag::remove_reps() {
	int removed_count = 0;
	size_type counter = 0;
	size_type counter2 = 0;

	node* cursor = head;
	node* cursor2 = cursor->get_next();
	node* temp = nullptr;

	//If not empty list, iterate through linked list and remove each elements duplicates
	if (get_size() != 0) {
		while (counter < get_size()) {

			//Loop through rest of array checking using cursor2 and checking it against cursor
			//To see if it should be removed
			cursor2 = cursor->get_next();
			counter2 = counter+1;
			while (counter2 < get_size()) {
				if (cursor2->get_data() == cursor->get_data()) {
					if (get_size() == 1) {
						temp = head;
						head = nullptr;
						tail = nullptr;
					}
					else if (cursor2 == tail) {
						temp = tail;
						tail->get_prev()->set_next(tail->get_next());
						tail->get_next()->set_prev(tail->get_prev());
						tail = tail->get_prev();
					}
					else {
						temp = cursor2;
						cursor2->get_prev()->set_next(cursor2->get_next());
						cursor2->get_next()->set_prev(cursor2->get_prev());
					}

					//Reset cursor and counter then delete temp and update values
					cursor2 = cursor2->get_prev();
					counter2--;

					delete(temp);
					size--;
					removed_count++;
				}
				cursor2 = cursor2->get_next();
				counter2++;
			}
			cursor = cursor->get_next();
			counter++;
		}
	}
	return removed_count;
}

void circular_bag::reverse() {
	size_type counter = 0;

	node* cursor = head;
	node* temp = cursor;

	//If no elements or only one element just return. Reverse is the exact same.
	if (size == 0 || size == 1) {
		return;
	}

	//Swap each element's next and prev nodes
	while (counter < get_size()) {
		temp = cursor->get_next();
		cursor->set_next(cursor->get_prev());
		cursor->set_prev(temp);

		cursor = cursor->get_prev();
		counter++;
	}

	//Update head and tail pointers
	temp = head;
	head = tail;
	tail = temp;
}

circular_bag::size_type circular_bag::get_count(const value_type& value) const {
	size_type count = 0;
	size_type counter = 0;

	node* cursor = head;

	while (counter < get_size()) {
		if (cursor->get_data() == value) count++;
		cursor = cursor->get_next();
	}

	return count;
}

void circular_bag::print_list() const {
	node* cursor = head;

	size_type index = 0;

	while (index < get_size()) {
		cout << "Value at position " << index << ": " << cursor->get_data() << endl;

		cursor = cursor->get_next();
		index++;
	}

	cout << endl;
}