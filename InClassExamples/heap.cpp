//Implimenting a priorty queue using the heap data structure (min heap)
class pqueue {
private:
	int *q;
	int size;
	int cap;
public:
	pqueue();
	~pqueue();
	pqueue(const pqueue &);

	void push(int);
	int pop();
	bool isEmpty();
	int getSize();

	//Clear by popping repeatedly
	void clearQ();

	//Self Check (is this the same), clear heap data, copy other head
	void operator =(const pqueue &);

	//Gets index of parent
	int getParent(int x) { return (x-1)/2; }
	//Gets index of left child. +1 for right child
	int getChild(int x) { return 2x+1; }

	//Swap two nodes
	void swap(int &a, int &b) { int temp = a; a = b; b = temp; }

	//Insert a node

	//Dynamically allocated array, so this expands it
	void expand();

	//Initialize array
	void init();

	//Clear the array
	void clear();

}

void pqueue::push(int data) {
	if(size == cap) expand();
	q[size++] = data;
	
	int start = size-1;
	while(start > 0) {
		if(q[start] < q[getParent(start)]) { 
			swap(q[start], q[getParent(start)]);
			start = getParent(start);
		} else {
			break;
		}
	}
}

void pqueue::pop() {
	
}