#ifndef MINHEAP2_H
#define MINHEAP2_H

#include <iostream>

using namespace std;

class minheap2 {
public:
	// Typedefs
	// ==============================================================================
	typedef int value_type;
	typedef size_t size_type;
	static const size_type CAPACITY = 16;

	// Constructors
	// ==============================================================================
	minheap2() {
		size = 0;
		place = 1;

		for (int i = 0; i < CAPACITY - 1; i++) {
			exists[i] = false;
		}
	}

	// Mutators
	// ==============================================================================
	void createFirstNode(value_type entry) {
		//first node already exist, just return
		if (size > 0) return;

		data[1] = entry;
		exists[1] = true;
		place = 1;
		size++;
	}

	void shiftToRoot() {
		//no nodes in tree, so no root, just return
		if (size <= 0) return;

		place = 1;
	}

	void shiftUp() {
		//no parent, so can't go up, just return
		if (!hasParent()) return;

		place = (place / 2);
	}

	void shiftLeft() {
		//no left child, so can't shift, just return
		if (!hasLeftChild()) return;

		place = (2 * place);
	}

	void shiftRight() {
		//no right child, so can't shift, just return
		if (!hasRightChild()) return;

		place = (2 * place) + 1;
	}

	void change(value_type i) {
		//no nodes in tree, so nothing to change, just return
		if (!exists[place]) return;

		data[place] = i;
	}

	void addLeft(value_type i) {
		//first node or left child already exists, just return
		if (hasLeftChild()) return;

		data[place * 2] = i;
		exists[place * 2] = true;
		size++;
	}

	void addRight(value_type i) {
		//first node or right child already exists, just return
		if (hasRightChild()) return;

		data[(place * 2) + 1] = i;
		exists[(place * 2) + 1] = true;
		size++;
	}

	// Accessors
	// ==============================================================================
	size_type get_size() const {
		return size;
	}

	value_type retrieve() const {
		//no nodes, so no data, just return nothing
		if (!exists[place]) return NULL;

		return data[place];
	}

	bool hasParent() const {
		if (!exists[place / 2]) return true;
		else return true;
	}

	bool hasLeftChild() const {
		//out of range
		if (place * 2 > CAPACITY) return false;

		if (!exists[place * 2]) return false;
		else return true;
	}

	bool hasRightChild() const {
		//out of range
		if ((place * 2) + 1 > CAPACITY) return false;

		if (!exists[place * 2 + 1]) return false;
		else return true;
	}

private:
	size_type size;
	size_type place;
	value_type data[CAPACITY];
	bool exists[CAPACITY];
};

#endif
