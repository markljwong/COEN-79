#ifndef SEQUENCE_H
#define SEQUENCE_H

using namespace std;

class sequence
{
public:
	typedef double value_type;
	typedef size_t size_type;
	static const size_type CAPACITY = 30;

	//Constructors and Destructors
	sequence();
	~sequence();

	//Iterators
	void start();
	value_type current() const;
	void advance();
	void move_to_end();
	bool is_item() const;

	//Mutators
	void insert(const value_type &);
	void attach(const value_type &);
	void add_front(const value_type &);
	void add_end(const value_type &);
	void remove_current();
	void remove_front();

	//Operators
	sequence operator +(const sequence &);
	void operator +=(const sequence &);

	//Accessors
	size_type get_size() const { return size; }

private:
	struct node {
		value_type data;
		node *next;
		node *prev;

		//constructor
		node(value_type x, node *n = nullptr, node *p = nullptr) {
			data = x;
			next = n;
			prev = p;
		}
	};

	node *head;
	node *tail;
	node *curr;
	size_type size;
};

#endif