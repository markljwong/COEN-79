#include <iostream>
using namespace std;

class queue {
	private:
		struct node {
			int data;
			node *next;

			//ctor
			node(int x, node *n = NULL) { 
				data = x; 
				next = n; 
			}
		};

		node *head;
		node *tail;
		int size;

	public:
		//ctor
		queue() { head = tail = NULL; size = 0; }
		//dtor
		~queue() { while(!isEmpty()) dequeue(); }
		//copyCtor
		queue(const queue &);

		//Operators
		queue operator +(const queue &);
		queue operator +=(const queue &);
		queue operator =(const queue &);

		//Allows non members to access private members
		friend operator +(const queue &, const queue &);

		//Mutators
		void enqueue(int);
		int dequeue();

		//Accessors
		bool isEmpty() { return (head == NULL) && (tail == NULL); }
		int size() { return size; }
}

void queue::enqueue(int newData) {
	if(isEmpty()) {
		head = tail = new node(newData);
	} else {
		tail->next = new node(newData);
		tail = tail->next;
	}
	size += 1;
}

int queue::dequeue() {
	int qData = head->data;

	node *tempNode = head->next;
	delete head;
	head = tempNode;

	if(isEmpty()) { tail = NULL; }

	size -= 1;

	return qData;
}

//Copy constructor
queue::queue(const queue &other) {
	head = tail = NULL; size = 0;
	if(!other.isEmpty()) {
		node *cursor = other.head;

		while(cursor != NULL) {
			enqueue(cursor->data);
			cursor = cursor->next;
			size += 1;
		}
	}
}

queue queue::operator +(const queue &RHS) {
	queue newQ(*this); //making newQ initialize to Q1
	if(!RHS.isEmpty()) {
		node *cursor = RHS.head;

		while(cursor != NULL) {
			newQ.enqueue(cursor->data);
			cursor = cursor->next;
			size += 1;
		}
	}

	return newQ;
}

//Alternative, but takes more memory and slower since tempQ must be created
// queue queue::operator +(const queue &RHS) {
// 		queue newQ(*this); //making newQ initialize to Q1
// 		queue tempQ(RHS);
// 		while(!RHS.isEmpty()) {
// 			newQ.enqueue(tempQ.dequeue());
// 		}
// 		return newQ;
// }

void queue::operator +=(const queue &RHS) {
	queue tempQ(RHS);
	while(!tempQ.isEmpty()) this->enqueue(tempQ.enqueue());
	return;
}

queue queue::operator =(const queue &RHS) {
	if(this == &RHS) return *this; //self assignment check
	while(!this->isEmpty()) this->dequeue(); //Clear existing data structure
	queue tempQ(RHS); //Copying new data in
	while(!tempQ.isEmpty()) this->enqueue(tempQ.dequeue());
	return *this;
}

bool operator <(const queue &LHS, const queue &RHS) {
	return LHS.size() < RHS.size();
}

bool operator >(const queue &LHS, const queue &RHS) {
	return LHS.size() < RHS.size();
}

bool operator ==(const queue &LHS, const queue &RHS) {
	return !(LHS < RHS) && !(LHS > RHS);
}

bool operator <=(const queue &LHS, const queue &RHS) {
	return !(LHS > RHS);
}

bool operator >=(const queue &LHS, const queue &RHS) {
	return !(LHS < RHS);
}

queue operator +(const queue &LHS, const queue &RHS) {
	queue newQ(LHS);
	if(!RHS.isEmpty()) {
		node *cursor = RHS.head;

		while(cursor != NULL) {
			newQ.enqueue(cursor->data);
			cursor = cursor->next;
		}
	}
	return newQ;
}