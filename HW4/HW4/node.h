#ifndef NODE_H
#define NODE_H

class node {
public:
	typedef double value_type;

	//CONSTRUCTOR
	node(value_type, node*, node*);

	//SETTERS
	void set_data(const value_type&);
	void set_next(node*);
	void set_prev(node*);

	//GETTERS
	value_type get_data() const;
	node* get_next() const;
	node* get_prev() const;

private:
	value_type data;
	node* next;
	node* prev;
};

#endif