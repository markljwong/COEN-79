#include "node.h"
#include "sequence.h"

sequence::sequence() {
	size = 0;

	head = nullptr;
	tail = nullptr;
	current = nullptr;
}

sequence::~sequence() {
	node* cursor = head;

	node* temp = nullptr;

	while (cursor != nullptr) {
		temp = cursor;
		cursor = cursor->get_next();
		delete(temp);
	}
}

void sequence::start() {
	current = head;
}

void sequence::end() {
	current = tail;
}

sequence::value_type sequence::sequence::get_current() const {
	return current->get_data();
}

void sequence::advance() {
	current = current->get_next();
}

void sequence::retreat() {
	current = current->get_prev();
}

//Insert an item before current
void sequence::insert(value_type new_data) {
	//Don't add the new_data if it already exists
	if (contains(new_data)) return;

	//Don't add, if current is not pointing at an item
	if (!is_item(current)) return;

	if (get_size() == 0) {
		head = tail = new node(new_data, nullptr, nullptr);
		current = head;
	}
	else if (current == head) {
		head->set_prev(new node(new_data, head, nullptr));
		head = head->get_prev();
		current = head;
	}
	else {
		node* new_node = new node(new_data, current, current->get_prev());
		current->set_prev(new_node);
		new_node->get_prev()->set_next(new_node);
		current = new_node;
	}
	size++;
}

//Attach an item after current
void sequence::attach(value_type new_data) {
	//Don't add the new_data if it already exists
	if (contains(new_data)) return;

	//Don't add, if current is not pointing at an item
	if (!is_item(current)) return;

	if (get_size() == 0) {
		head = tail = new node(new_data, nullptr, nullptr);
		current = head;
	}
	else if (current == tail) {
		tail->set_next(new node(new_data, nullptr, tail));
		tail = tail->get_next();
		current = tail;
	}
	else {
		node* new_node = new node(new_data, current, current->get_prev());
		current->set_next(new_node);
		new_node->get_next()->set_prev(new_node);
		current = new_node;
	}
	size++;
}

void sequence::remove_current() {
	//Don't remove, if current is not pointing at an item
	if (!is_item(current)) return;

	node* temp;

	if (size == 1) {
		temp = head;
		head = nullptr;
		tail = nullptr;
	}
	else if (current == head) {
		temp = head;
		head = head->get_next();
		head->set_prev(nullptr);
	}
	else if (current == tail) {
		temp = tail;
		tail = tail->get_prev();
		tail->set_next(nullptr);
	}
	else {
		temp = current;
		current->get_prev()->set_next(current->get_next());
		current->get_next()->set_prev(current->get_prev());
	}

	delete(temp);
	size--;
}

void sequence::insert_front(value_type new_data) {
	if (get_size() == 0) {
		head = tail = new node(new_data, nullptr, nullptr);
	}
	else {
		head->set_prev(new node(new_data, head, nullptr));
		head = head->get_prev();
	}

	current = head;
	size++;
}

void sequence::attach_back(value_type new_data) {
	if (get_size() == 0) {
		head = tail = new node(new_data, nullptr, nullptr);
	}
	else {
		tail->set_next(new node(new_data, nullptr, tail));
		tail = tail->get_next();
	}

	current = tail;
	size++;
}

void sequence::remove_front() {
	//Check size
	if (size <= 0) return;

	node* temp;

	if (size == 1) {
		temp = head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		temp = head;
		head = head->get_next();
		head->set_prev(nullptr);
	}

	size--;
}

//Getters
bool sequence::is_item(node* n) const {
	return (n != nullptr);
}

sequence::size_type sequence::get_size() const {
	return size;
}

//Determines if set contains given value
bool sequence::contains(value_type value) const {
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
sequence::value_type sequence::operator [](size_type index) const {
	//Make sure the index is within size of linked list
	if (index >= size) return -1;

	size_type counter = 0;
	node * cursor = head;

	while (cursor != nullptr && counter != index) {
		cursor = cursor->get_next();
		counter++;
	}

	return cursor->get_data();
}
