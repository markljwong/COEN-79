//Midterm 

// Layout (12 Questions, 3 Each)
// ==============================
// 4%		Name and ID
// 28%		Question and Answer
// 28%		Programming
// 20%		Matching
// 20%		Drawing
// -
// 12%		Extra Credit

// Content
// ==============================
// - Template
// - Iterators
// - Priority Queue
// 	- Binary Heap
// 	- Binomial Heap
// - Set
// - Sequence
// - Bag
// - Keyed Bag
// - Inheritance
// 	- Derive a class
// 	- Know what is being inherited
// 	- How to implement a derived class constructor using parent class constructor
// - Doubly Linked List
// - STL (Standard Library)
// 	- For own benefit
// 	- Vectors
// 	- Lists

// 6 Iterator Functions
// ==============================
// - iterator operator ++()
// - iterator operator ++(int)
// - iterator operator --()
// - iterator operator --(int)
// - T operator *()
// - bool operator ==(iterator)

// Example For Singlely Linked List
// ------------------------------
class iteratorX {
private:
	node* it;
	node* begin;
public:
	iteratorX(node* n) { it = n; }
	void setBegin(node* b) { begin = b; }
};

iteratorX iteratorX::operator ++() {
	it = it->next();
	return iteratorX(it);
}

iteratorX iteratorX::operator ++(int i) {
	iterator iteratorX(temp);
	it = it->next();
	return temp;
}

iterator iteratorX::operator --() {
	node* p = begin;
	while(p != NULL && p->next() != it) p = p->next;
	it = p;
	return iterator(it);
}

T iteratorX::operator *() {
	return it->data();
}

bool iteratorX::operator ==(iteratorX other) {
	return this->it == other.it;
}

// Example for Inheritance and Templates
// -------------------------------------
// Base class
template<typename T>
class base {
public:
	b(int, float);
};

// If derived not template 
class derived: public base<int> {
public:
	D() {}
	D(): B(xyz) {}
};

// If derived also template
template<typename R>
class derived: public base<R> {
	D(): B<R>(int) {}
}