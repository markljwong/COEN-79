#ifndef SET_H
#define SET_H

#include "node.h"
#include <iostream>
#include <iterator>

using namespace std;

//V is the value type and S is the size type
template <typename V, typename S>
class set {
public:
	class Iterator {
	public:
		Iterator(node* n) {
			it = n;
		}

		Iterator operator ++() { //pre
			if (it != nullptr) {
				it = it->get_next();
			}

			return it;
		}

		Iterator operator ++(int i) { //post
			node* temp = it;
			if (it != nullptr) {
				it = it->get_next();
			}
			return temp;
		}

		Iterator operator --() { //pre
			if (it != nullptr) {
				it = it->get_prev();
			}

			return it;
		}

		Iterator operator --(int i) { //post
			node* temp = it;
			if (it != nullptr) {
				it = it->get_prev();
			}
			return temp;
		}

		bool operator !=(const Iterator& other) {
			return it != other.it;
		}

		V operator *() {
			return it->get_data();
		}
	private:
		node* it;
	};

	//Constructors
	set() {
		size = 0;

		head = nullptr;
		tail = nullptr;
	}

	~set() {
		node* cursor = head;

		node* temp = nullptr;

		while (cursor != nullptr) {
			temp = cursor;
			cursor = cursor->get_next();
			delete(temp);
		}
	}

	//Setters
	void insert(V new_data) {
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

	bool erase(V value) {
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

	//Getters
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

	//iterator
	Iterator begin() {
		return Iterator(head);
	}
	Iterator end() {
		return Iterator(tail);
	}

private:
	S size;

	node* head;
	node* tail;
};

#endif
