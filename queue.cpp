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

		//Appends another queue to this queue
		queue operator +(const queue &);

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
	queue newQ(*this);
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