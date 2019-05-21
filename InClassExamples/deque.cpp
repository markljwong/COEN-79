//The child class (e.g. deque) inherents everything except the private parts of the parent class (e.g. list)
//This includes both the public and protected parts of the parent class
//However the exception are the constructors and destructors of the parent which are inherent to the class

//If inheriting as a public class, 
//private -> NA
//public -> public
//protected -> private

//If inheriting as a private class,
//private -> NA
//public -> private
//protected -> private

//To cleanly develop inheritance, always inherit privately, and then re-expose what is needed

class deque : private list {
public:
	deque(int new_size = 255) : list(new_size) { }
	~deque() { };
	deque(const deque &other) { *this=other; };

	deque operator =(const deque &RHS) { list::operator =(RHS); }

	void pushFront(int);
	void pushBack(int);
	int popFront();
	int popBack();

	//Re-exposition to make the private function from the parent public again
	bool list::isEmpty();
	//OR make isEmpty again
	//bool isEmpty();
}

void deque::pushFront(int new_data) {
	start();
	insertBefore(new_data);
}

void deque::pushBack(int new_data) {
	end();
	insertAfter(new_data);
}

int deque::popFront() {
	start();
	return remove();
}

int deque::popBack() {
	start();
	return remove();
}

// If not using re-exposition method
// bool deque::isEmpty() {
// 	return list::isEmpty();
// }

// Example of using inherited functions
// class X {
// private:
// 	int a;
// 	float b;
// public:
// 	X(int aa, float bb) { a=aa; b=bb; }
// 	//X(int aa, float bb) : a(aa), b(bb) {};
// }