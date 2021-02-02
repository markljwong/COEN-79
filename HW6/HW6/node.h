#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename Item>
class node {
public:
	//Constructors
	node(Item i,  node<Item>* p = nullptr, node<Item>* l = nullptr, node<Item>* r = nullptr) {
		data = i;
		parent = p;
		left = l;
		right = r;
	}

	~node() {
		delete(parent);
		delete(left);
		delete(right);
	}

	//Mutators
	void setData(Item i) { data = i; }
	void setParent(node<Item>* n) { parent = n; }
	void setLeft(node<Item>* n) { left = n; }
	void setRight(node<Item>* n) { right = n; }

	//Accessors
	Item getData() const { return data; }
	node<Item>* getParent() const { return parent; }
	node<Item>* getLeft() const { return left; }
	node<Item>* getRight() const { return right; }

private:
	Item data;
	node<Item>* parent;
	node<Item>* left;
	node<Item>* right;
};

#endif
