/*
 * LectureA.h
 *
 *  Created on: April 29, 2019
 *      Author: Hien T. Vu
 */

#ifndef LECTUREA_H_
#define LECTUREA_H_

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

namespace LectureA {

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
	// CONSTRUCTORS and DESTRUCTOR
	//Bag();
	//Bag(const Bag&);
	//~Bag();
	// MEMBER METHODS
	//Bag& operator=(const Bag&);
	void insert(const T&);
	bool erase_one(const T&);
	int erase(const T&);
	void operator+=(const Bag&);
	void operator-=(const Bag&);
	int size() const {
		return data.size();
	}
	int count(const T&) const;
	T grab() const;
	friend bool operator==<>(const Bag&, const Bag&);
	friend Bag operator&<>(const Bag&, const Bag&);
	void print();
	class iterator {
	public:
		iterator(const T&, Bag&);
		iterator(typename std::vector<T>::iterator);
		T operator*();
		iterator operator++();
		iterator operator++(int);
		iterator operator--();
		iterator operator--(int);
		bool operator==(iterator);
		bool operator!=(iterator);
	private:
		typename std::vector<T>::iterator it;
	};
	iterator begin();
	iterator end();
private:
	std::vector<T> data;
};

// NON-MEMBER FUNCTIONS
template<typename T>
Bag<T> operator+(const Bag<T>&, const Bag<T>&);

///////////////////////////////
// Implementation
///////////////////////////////
template<typename T>
void Bag<T>::insert(const T& entry) {
	data.push_back(entry);
}

template<typename T>
bool Bag<T>::erase_one(const T& target) {
	typename std::vector<T>::iterator it = std::find(data.begin(), data.end(),
			target);
	if (it != data.end()) {
		*it = data[size() - 1];
		data.pop_back();
		return true;
	}
	return false;
}

template<typename T>
int Bag<T>::erase(const T& target) {
	int answer = 0;
	while (erase_one(target)) {
		answer++;
	}
	return answer;
}

template<typename T>
void Bag<T>::operator+=(const Bag& addend) {
	int N = size() + addend.size();
	std::vector<T> new_data(N);
	std::merge(data.begin(), data.end(), addend.data.begin(), addend.data.end(),
			new_data.begin());
	data = new_data;
}

template<typename T>
void Bag<T>::operator-=(const Bag& other) {
	for (typename std::vector<T>::const_iterator it = other.data.begin();
			it != other.data.end(); it++) {
		erase_one(*it);
	}
}

template<typename T>
int Bag<T>::count(const T& target) const {
	return std::count(data.begin(), data.end(), target);
}

template<typename T>
T Bag<T>::grab() const {
	assert(size() > 0);
	int i = (rand() % size());
	return data[i];
}

template<typename T>
void Bag<T>::print() {
	std::cout << "(" << size() << ") ";
	typename std::vector<T>::iterator it = data.begin();
	while (it != data.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

template<typename T>
bool operator==(const Bag<T>& b1, const Bag<T>& b2) {
	if (b1.size() != b2.size())
		return false;
	return std::equal(b1.data.begin(), b1.data.end(), b2.data.begin());
}

template<typename T>
Bag<T> operator&(const Bag<T>& b1, const Bag<T>& b2) {
	Bag<T> answer;
	for (typename std::vector<T>::const_iterator it = b1.data.begin();
			it != b1.data.end(); it++) {
		if (b2.count(*it) > answer.count(*it))
			answer.insert(*it);
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
	it = std::find(B.data.begin(), B.data.end(), x);
	// default to the last element if not found
	if (it == B.data.end())
		it--;
}

template<typename T>
Bag<T>::iterator::iterator(typename std::vector<T>::iterator p) {
	it = p;
}

template<typename T>
T Bag<T>::iterator::operator*() {
	return *it;
}

template<typename T>
typename Bag<T>::iterator Bag<T>::iterator::operator++() {
	return iterator(++it);
}

template<typename T>
typename Bag<T>::iterator Bag<T>::iterator::operator++(int i) {
	typename Bag<T>::iterator save = *this;
	it++;
	return save;
}

template<typename T>
typename Bag<T>::iterator Bag<T>::iterator::operator--() {
	return iterator(--it);
}

template<typename T>
typename Bag<T>::iterator Bag<T>::iterator::operator--(int i) {
	typename Bag<T>::iterator save = *this;
	it--;
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
	return iterator(data.begin());
}

template<typename T>
typename Bag<T>::iterator Bag<T>::end() {
	return iterator(data.end() - 1);
}

} // end of namespace

#endif /* LECTUREA_H_ */
