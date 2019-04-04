#include <iostream>
using namespace std;

class stack {
	private:
		int maxSize;
		int count;
		int *A;
	public:
		//ctor = constructor
		stack(); 
		//dtor = destructor
		~stack();
		//copyConstructor: makes a duplicate stack
		void stack(const stack &);

		//Mutators: changes the object
		void push(int);
		int pop();

		//Accessors: gets information from object
		bool isEmpty();
		int top();
}

stack::stack(int n = 10) {
	maxSize = n;
	count = 0;
	A = new int[n];
}

stack::stack(const stack &other) {
	this->maxSize = other.maxSize; 	//this can be skipped
	(*this).c = other.c;			//Different method of self reference
	A = new int[maxSize];

	for(int iii = 0; iii < c; iii++) {
		A[iii] = other.A[iii];		
	}
}

stack::~stack() {
	delete[] A;
}


void main() {
	stack A1;
}