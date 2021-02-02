#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include "node.h"

using namespace std;

template <typename Item>
class bintree {
public:
	// Constructors
	// ==============================================================================
	bintree() {
		size = 0;
		current = nullptr;
		root = nullptr;
	}

	// Mutators
	// ==============================================================================
	void createFirstNode(Item entry) {
		//first node already exist, just return
		if (size > 0) return;

		root = new node<Item>(entry);
		current = root;
		size++;
	}

	void shiftToRoot() {
		//no nodes in tree, so no root, just return
		if (size <= 0) return;

		current = root;
	}

	void shiftUp() {
		//no parent, so can't go up, just return
		if (!hasParent()) return;

		current = current->getParent();
	}

	void shiftLeft() {
		//no left child, so can't shift, just return
		if (!hasLeftChild()) return;

		current = current->getLeft();
	}

	void shiftRight() {
		//no right child, so can't shift, just return
		if (!hasRightChild()) return;

		current = current->getRight();
	}

	void change(Item i) {
		//no nodes in tree, so nothing to change, just return
		if (size <= 0) return;

		current->setData(i);
	}

	void addLeft(Item i) {
		//first node or left child already exists, just return
		if (size <= 0 || hasLeftChild()) return;

		current->setLeft(new node<Item>(i, current, nullptr, nullptr));
		size++;
	}

	void addRight(Item i) {
		//first node or right child already exists, just return
		if (size <= 0 || hasRightChild()) return;

		current->setRight(new node<Item>(i, current, nullptr, nullptr));
		size++;
	}

	// Accessors
	// ==============================================================================
	size_t get_size() const {
		return size;
	}

	Item retrieve() const {
		//no nodes, so no data, just return nothing
		if (size <= 0) return NULL;

		return current->getData();
	}

	bool hasParent() const {
		//no nodes, so no data, just return false
		if (size <= 0) return false;

		if (current->getParent() != nullptr) return true;
		else return false;
	}

	bool hasLeftChild() const {
		//no nodes, so no data, just return false
		if (size <= 0) return false;

		if (current->getLeft() != nullptr) return true;
		else return false;
	}

	bool hasRightChild() const {
		//no nodes, so no data, just return false
		if (size <= 0) return false;

		if (current->getRight() != nullptr) return true;
		else return false;
	}

private:
	size_t size;
	node<Item>* current;
	node<Item>* root;
};

#endif
