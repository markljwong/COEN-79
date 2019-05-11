#include "keyed_bag.h"
#include <iostream>

//Constructor
keyed_bag::keyed_bag() {
	size = 0;

	data_head = nullptr;
	data_tail = nullptr;

	keys_head = nullptr;
	keys_tail = nullptr;
}

//Destructor
keyed_bag::~keyed_bag() {
	node* datacursor = data_head;
	node* keyscursor = keys_head;

	node* temp = nullptr;

	while (datacursor != nullptr) {
		temp = datacursor;
		datacursor = datacursor->get_next();
		delete(temp);

		temp = keyscursor;
		keyscursor = keyscursor->get_next();
		delete(temp);
	}
}

//Insert an item at end of the set
void keyed_bag::insert(value_type new_data, value_type key) {
	if (get_size() == 0) {
		data_head = data_tail = new node(new_data, nullptr, nullptr);
		keys_head = keys_tail = new node(key, nullptr, nullptr);
	}
	else {
		data_tail->set_next(new node(new_data, nullptr, data_tail));
		data_tail = data_tail->get_next();

		keys_tail->set_next(new node(key, nullptr, keys_tail));
		keys_tail = keys_tail->get_next();
	}

	size++;
}

bool keyed_bag::erase(value_type key) {
	node* datacursor = data_head;
	node* keyscursor = keys_head;

	node* datatemp = nullptr;
	node* keystemp = nullptr;

	//Attempt to find the keyed element and remove accordingly
	while (keyscursor != nullptr) {
		if (keyscursor->get_data() == key) {
			if (size == 1) {
				datatemp = data_head;
				data_head = nullptr;
				data_tail = nullptr;

				keystemp = keys_head;
				keys_head = nullptr;
				keys_tail = nullptr;
			}
			else if (keyscursor == keys_head) {
				datatemp = data_head;
				data_head = data_head->get_next();
				data_head->set_prev(nullptr);

				keystemp = keys_head;
				keys_head = keys_head->get_next();
				keys_head->set_prev(nullptr);
			}
			else if (keyscursor == keys_tail) {
				datatemp = data_tail;
				data_tail = data_tail->get_prev();
				data_tail->set_next(nullptr);

				keystemp = keys_tail;
				keys_tail = keys_tail->get_prev();
				keys_tail->set_next(nullptr);
			}
			else {
				datatemp = datacursor;
				datacursor->get_prev()->set_next(datacursor->get_next());
				datacursor->get_next()->set_prev(datacursor->get_prev());

				keystemp = keyscursor;
				keyscursor->get_prev()->set_next(keyscursor->get_next());
				keyscursor->get_next()->set_prev(keyscursor->get_prev());
			}

			delete(datatemp);
			delete(keystemp);
			size--;

			return true;
		}

		datacursor = datacursor->get_next();
		keyscursor = keyscursor->get_next();
	}

	//If function reaches here, it isn't found or empty list
	return false;
}

//Returns size of set
keyed_bag::size_type keyed_bag::get_size() const {
	return size;
}

//Determines if set contains given value
bool keyed_bag::contains(value_type key) const {
	node* keyscursor = keys_head;

	while (keyscursor != nullptr) {
		if (keyscursor->get_data() == key) return true;
		keyscursor = keyscursor->get_next();
	}

	//If function reaches here, it isn't found
	return false;
}