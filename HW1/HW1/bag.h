#ifndef BAG_H
#define BAG_H

class bag
{
public:
	typedef double value_type;
	typedef size_t size_type;
	static const size_type CAPACITY = 30;

	//Constructors and Destructors
	bag();
	~bag();

	//Operators
	bag operator +(const bag &);
	void operator +=(const bag &);
	bag operator -(const bag &);
	void operator -=(const bag &);

	//Mutators
	void insert(int);
	size_type erase(const value_type &);
	bool erase_one(const value_type &);
	bool remove_reps();

	//Accessors
	size_type get_size() const { return size; }
	size_type get_count(const value_type &) const;

private:
	struct node {
		value_type data;
		node *next;
		node *prev;

		//ctor
		node(value_type x, node *n = nullptr, node *p = nullptr) {
			data = x;
			next = n;
			prev = p;
		}
	};

	node *head;
	node *tail;
	size_type size;


};

//NON MEMBER FUNCTIONS
bool operator ==(const bag&, const bag&);

#endif