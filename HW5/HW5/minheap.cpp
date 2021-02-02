#include "minheap.h"
#include <iostream>

using namespace std;

minheap::minheap() {
	size = 0;
}


//Add value to the queue if not at capacity
void minheap::push(const value_type& new_data) {
	//If at or somehow over capacity just return and don't add
	if (get_size() >= CAPACITY) return;

	data[size] = new_data;
	order[size] = place;
	swap(0, get_size());
	place++;
	size++;

	for (size_type i = get_size() - 1; i > 0; i = i / 2) {
		if (compare(i, i / 2) == -1) swap(i, i / 2);
		else break;
	}
}


//Removes minimum from the queue
minheap::value_type minheap::pop() {
	//If at or somehow below 0, then just return -1 since nothing to pop
	if (get_size() <= 0) return -1;

	value_type temp = data[0];
	data[0] = data[get_size() - 1];
	size--;

	size_type index;

	for (size_type i = 0; i < get_size() - 1; i = index) {
		if (compare(2 * i, 2 * i + 1) == -1) index = 2 * i;
		else index = 2 * i + 1;
		if (compare(i, index) == 1) swap(i, index);
		else break;
	}

	return temp;
}


//Swaps two elements at given indices within array
void minheap::swap(size_type in1, size_type in2) {
	value_type temp_data = data[in1];
	int temp_order = order[in1];

	data[in1] = data[in2];
	order[in1] = order[in2];

	data[in2] = temp_data;
	order[in2] = temp_order;
}


//Compare two elemnts at given indices based on PRIORITY not VALUE
//First compares value, and returns 1 if v1 > v2 and -1 if v1 < v2
//If equal, compares order, and returns 1 if order of v1 > order of v2 and -1 if order of v1 < order of v2
//Otherwise return 0
int minheap::compare(size_type v1, size_type v2) const {
	//If either index greater of equal to size return since index out of bounds
	if (v1 >= get_size() || v2 >= get_size()) 0;

	if (data[v1] > data[v2]) return 1;
	else if (data[v1] < data[v2]) return -1;

	if (order[v1] > order[v2]) return 1;
	else return -1;
}


minheap::size_type minheap::get_size() const {
	return size;
}