class orderedlist : private list {
public:
	//Constructors and Destructors
	orderedlist(int new_size = 100) : list(new_size) { };
	//~orderedlist(); By default, the compiler will call the inherited destructor
	orderedlist(const orderedlist &other) { *this = other; }

	//Operators
	orderedlist operator =(const orderedlist &RHS) { list::operator =(RHS); }

	void insertBefore(int);
	void insertAfter(int);
	void replace(int);
}

void orderedlist::insertBefore(int data) {
	for(start(), int i = 0; i < size(); forward(), i++) {
		if(current() > data) break;
	}

	list::insertBefore(data);
}

void orderedlist::insertAfter(int data) {
	insertBefore(data);
}

void ordererlist::replace(int data) {
	list::remove(current());
	insertBefore(data);
}