#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "node.h"
#include <iostream>

//V is the value type and S is the size type
template <typename V, typename S>
class sequence {
public:
	//Constructors
	sequence() {
		size = 0;

		head = nullptr;
		tail = nullptr;
		current = nullptr;
	}

	~sequence() {
		node* cursor = head;

		node* temp = nullptr;

		while (cursor != nullptr) {
			temp = cursor;
			cursor = cursor->get_next();
			delete(temp);
		}
	}

	//Setters
	void start() {
		current = head;
	}

	void end() {
		current = tail;
	}

	V get_current() const {
		return current->get_data();
	}

	void advance() {
		current = current->get_next();
	}

	void retreat() {
		current = current->get_prev();
	}

	void insert(V new_data) {
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

	void attach(V new_data) {
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

	void remove_current() {
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

	void insert_front(V new_data) {
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

	void attach_back(V new_data) {
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

	void remove_front() {
		//Check size
		if (size <= 0) return;

		node * temp;

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
	bool is_item(node* n) const {
		return (n != nullptr);
	}

	S get_size() const {
		return size;
	}

	bool contains(V value) const {
		node* cursor = head;

		while (cursor != nullptr) {
			if (cursor->get_data() == value) return true;
			cursor = cursor->get_next();
		}

		//If function reaches here, it isn't found
		return false;
	}

	V operator [](S index) const {
		//Make sure the index is within size of linked list
		if (index >= size) return -1;

		S counter = 0;
		node * cursor = head;

		while (cursor != nullptr && counter != index) {
			cursor = cursor->get_next();
			counter++;
		}

		return cursor->get_data();
	}

private:
	S size;
	node* head;
	node* tail;
	node* current;
};

#endif
