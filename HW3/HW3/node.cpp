#include "node.h"
#include <iostream>

//Constructor
node::node(value_type x, node* n = nullptr, node* p = nullptr) {
	data = x;
	next = n;
	prev = p;
}

//Setters
void node::set_data(const value_type& x) { data = x; }
void node::set_next(node* n) { next = n; }
void node::set_prev(node* p) { prev = p; }

//Getters
node::value_type node::get_data() const { return data; }
node* node::get_next() const { return next; }
node* node::get_prev() const { return prev; }