//Unfinished list

#include <iostream>

using namespace std;

class list {
public:
	list(int = 10);
	~list();
	list(const list &);
	list operator =(const list &);

	//Accessors
	int size();
	bool isEmpty();

	//Mutators
	void remove(int);
	void insertBefore(int);
	void insertAfter(int);
	int replace(int);
	void clearList();
	void sort();

	//Iterators
	void start()
	void end();
	void forward();
	void backword();
	void jump(int);

private:
	int size;
	int max_size;
	int p;
	int ln*;

	int current() { return ln[p]; };
}

list::list(int new_size) {
	max_size = new_size;
	ln = new int[new_size];
}

void list::remove(int) {

}

void list::insertBefore(int) {

}

void list::insertAfter(int) {

}

int list::replace(int) {

}

void list::clearList() {

}

void list::sort() {

}

void list::start() {
	p = 0;
}

void list::end() {
	p = size-1;
}

void list::forward() {
	p++;
	//Reset if going too far forward
	if(p >= size) p = size-1;
}

void list::backward() {
	p--;
	//Reset if going too far backward
	if(p <= 0) p = 0;
}

void list::jump(int jump) {

}