/*
 * LectureB.h
 *
 *  Created on: May 1, 2019
 *      Author: Hien T. Vu
 */

#ifndef LECTUREB_H_
#define LECTUREB_H_

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

namespace LectureB {

///////////////////////////////
// Interface
///////////////////////////////

// Prototype class Bag for template functions
template<typename T> class Bag;

// Prototype template functions to include as friend in the class Bag
template<typename T> bool operator==(const Bag<T>&, const Bag<T>&);
template<typename T> Bag<T> operator&(const Bag<T>&, const Bag<T>&);

// Class Bag
template<typename T>
class Bag {
public:
	// doubly linked list
	struct node {
		node* prev;
		T data;
		node* next;
		node(node* p, T d, node* n) :
				prev(p), data(d), next(n) { /* do nothing */
		}
	};
	// CONSTRUCTORS and DESTRUCTOR
	Bag() {
		init();
	}
	Bag(const Bag&);
	~Bag() {
		clear();
	}
	// MEMBER METHODS
	Bag& operator=(const Bag&);
	void insert(const T&);
	bool erase_one(const T&);
	int erase(const T&);
	void operator+=(const Bag&);
	void operator-=(const Bag&);
	int size() const {
		return _size;
	}
	int count(const T&) const;
	T grab() const;
	friend bool operator==<>(const Bag&, const Bag&);
	friend Bag operator&<>(const Bag&, const Bag&);
	void print();
	class iterator {
	public:
		iterator(const T&, Bag&);
		iterator(typename LectureB::Bag<T>::node*);
		T operator*();
		iterator operator++();
		iterator operator++(int);
		iterator operator--();
		iterator operator--(int);
		bool operator==(iterator);
		bool operator!=(iterator);
	private:
		node* it;
	};
	iterator begin();
	iterator end();
private:
	node* head;
	node* tail;
	int _size;
	void clear();
	void init();
};

// NON-MEMBER FUNCTIONS
template<typename T>
Bag<T> operator+(const Bag<T>&, const Bag<T>&);

///////////////////////////////
// Implementation
///////////////////////////////
template<typename T>
void Bag<T>::clear() {
	while (head) {
		node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

template<typename T>
void Bag<T>::init() {
	head = NULL;
	tail = NULL;
	_size = 0;
}

template<typename T>
Bag<T>::Bag(const Bag& other) {
	init();
	*this = other;
}

template<typename T>
Bag<T>& Bag<T>::operator=(const Bag& other) {
	if (this == &other)
		return *this;
	clear();
	init();
	node* ptr = other.head;
	while (ptr) {
		insert(ptr->data);
		ptr = ptr->next;
	}
	return *this;
}

template<typename T>
void Bag<T>::insert(const T& entry) {
	if (_size == 0) {
		tail = head = new node(NULL, entry, NULL);
	} else {
		tail = tail->next = new node(tail, entry, NULL);
	}
	_size++;
}

template<typename T>
bool Bag<T>::erase_one(const T& target) {
	node* ptr = head;
	while (ptr && ptr->data != target)
		ptr = ptr->next;
	if (ptr) {
		if (ptr->prev == NULL && ptr->next == NULL) { // only node
			tail = head = NULL;
		} else if (ptr->prev == NULL) { // first node
			head = head->next;
			head->prev = NULL;
		} else if (ptr->next == NULL) { // last node
			tail = tail->prev;
			tail->next = NULL;
		} else { // middle node
			ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;
		}
		delete ptr;
		_size--;
		return true;
	}
	return false;
}

template<typename T>
int Bag<T>::erase(const T& target) {
	int answer = 0;
	while (erase_one(target))
		answer++;
	return answer;
}

template<typename T>
void Bag<T>::operator+=(const Bag& addend) {
	node* ptr = addend.head;
	while (ptr) {
		this->insert(ptr->data);
		ptr = ptr->next;
	}
}

template<typename T>
void Bag<T>::operator-=(const Bag& other) {
	node* ptr = other.head;
	while (ptr) {
		erase_one(ptr->data);
		ptr = ptr->next;
	}
}

template<typename T>
int Bag<T>::count(const T& target) const {
	int count = 0;
	node* ptr = head;
	while (ptr) {
		if (ptr->data == target)
			count++;
		ptr = ptr->next;
	}
	return count;
}

template<typename T>
T Bag<T>::grab() const {
	assert(size() > 0);
	int i = (rand() % size()) + 1;
	node* ptr = head;
	int j = 0;
	while (j++ != i)
		ptr = ptr->next;
	return ptr->data;
}

template<typename T>
void Bag<T>::print() {
	std::cout << "(" << size() << ") ";
	node* ptr = head;
	while (ptr) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

template<typename T>
bool operator==(const Bag<T>& b1, const Bag<T>& b2) {
	if (b1.size() != b2.size())
		return false;
	typename Bag<T>::node* p1 = b1.head;
	typename Bag<T>::node* p2 = b2.head;
	while (p1 && p2) {
		if (p1->data != p2->data)
			return false;
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}

template<typename T>
Bag<T> operator&(const Bag<T>& b1, const Bag<T>& b2) {
	Bag<T> answer;
	typename Bag<T>::node* ptr = b1.head;
	while (ptr) {
		if (b2.count(ptr->data) > answer.count(ptr->data))
			answer.insert(ptr->data);
		ptr = ptr->next;
	}
	return answer;
}

template<typename T>
Bag<T> operator+(const Bag<T>& b1, const Bag<T>& b2) {
	Bag<T> answer;
	answer += b1;
	answer += b2;
	return answer;
}

template<typename T>
Bag<T>::iterator::iterator(const T& x, Bag& B) {
	it = B.head;
	while (it && it->data != x)
		it = it->next;
	// default to the last element if not found
	if (it == NULL)
		it = B.tail;
}

template<typename T>
Bag<T>::iterator::iterator(typename LectureB::Bag<T>::node* p) {
	it = p;
}

template<typename T>
T Bag<T>::iterator::operator*() {
	return it->data;
}

template<typename T>
typename Bag<T>::iterator Bag<T>::iterator::operator++() {
	if (it)
		it = it->next;
	return iterator(it);
}

template<typename T>
typename Bag<T>::iterator Bag<T>::iterator::operator++(int i) {
	typename Bag<T>::iterator save = *this;
	if (it)
		it = it->next;
	return save;
}

template<typename T>
typename Bag<T>::iterator Bag<T>::iterator::operator--() {
	if (it)
		it = it->prev;
	return iterator(it);
}

template<typename T>
typename Bag<T>::iterator Bag<T>::iterator::operator--(int i) {
	typename Bag<T>::iterator save = *this;
	if (it)
		it = it->prev;
	return save;
}

template<typename T>
bool Bag<T>::iterator::operator==(iterator other) {
	return it == other.it;
}

template<typename T>
bool Bag<T>::iterator::operator!=(iterator other) {
	return it != other.it;
}

template<typename T>
typename Bag<T>::iterator Bag<T>::begin() {
	return iterator(head);
}

template<typename T>
typename Bag<T>::iterator Bag<T>::end() {
	return iterator(tail);
}

} // end of namespace

#endif /* LECTUREB_H_ */
