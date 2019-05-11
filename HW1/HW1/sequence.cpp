#include "sequence.h"

using namespace std;

//Constructor
sequence::sequence()
{
	head = nullptr;
	tail = nullptr;
	curr = nullptr;
	size = 0;
}

//Destructor
sequence::~sequence()
{
	node *cursor = head;
	node *temp = nullptr;
	while (cursor != nullptr)
	{
		temp = cursor;
		cursor = cursor->next;
		delete(temp);
	}
}

//Starts iteration through sequence
void sequence::start()
{
	if (get_size() > 0)
	{
		curr = head;
	}
	return;
}

//Return data stored at curr item
sequence::value_type sequence::current() const
{
	return curr->data;
}

//Advances to next item in sequence, or nullptr if tail
void sequence::advance()
{
	if (is_item())
	{
		curr = curr->next;
	}
}

//Moves curr to end of sequence
void sequence::move_to_end()
{
	curr = tail;
}

//Returns bool if curr is pointing at item or not
bool sequence::is_item() const
{
	if (curr != nullptr) return true;
	else return false;
}

//Insert new_data before curr
void sequence::insert(const value_type &new_data)
{
	//Empty so just add new_data, or insert if less than capacity, otherwise do nothing.
	if (get_size() == 0)
	{
		curr = head = tail = new node(new_data);
		size += 1;
	}
	else if(get_size() < CAPACITY)
	{
		node *new_node = new node(new_data, curr, curr->prev);
		curr->prev = new_node;
		curr = new_node;
		size += 1;
	} 

	return;
}

//Attach new_data after curr
void sequence::attach(const value_type &new_data)
{
	//Empty so just add new_data, or insert if less than capacity, otherwise do nothing.
	if (get_size() == 0)
	{
		curr = head = tail = new node(new_data);
		size += 1;
	}
	else if (get_size() < CAPACITY)
	{
		node *new_node = new node(new_data, curr->next, curr);
		curr->next = new_node;
		curr = new_node;
		size += 1;
	}

	return;
}

//Add new_data to the front
void sequence::add_front(const value_type &new_data)
{
	//Empty so just add new_data, or insert if less than capacity, otherwise do nothing.
	if (get_size() == 0)
	{
		head = tail = new node(new_data);
		size += 1;
	}
	else if (get_size() < CAPACITY)
	{
		node *new_node = new node(new_data, head, nullptr);
		head->prev = new_node;
		head = new_node;
		size += 1;
	}

	size += 1;
	return;
}

//Add new_data to the end
void sequence::add_end(const value_type &new_data)
{
	//Empty so just add new_data, or insert if less than capacity, otherwise do nothing.
	if (get_size() == 0)
	{
		head = tail = new node(new_data);
		size += 1;
	}
	else if (get_size() < CAPACITY)
	{
		node *new_node = new node(new_data, nullptr, tail);
		tail->next = new_node;
		tail = new_node;
		size += 1;
	}

	return;
}

//Removes curr item from sequence and advances iteration
void sequence::remove_current()
{
	//If curr exist, then remove
	if (is_item())
	{
		if (curr == head)
		{
			node *temp = head;
			head = head->next;
			head->prev = nullptr;
			curr = head;
			delete(temp);
		}
		else if (curr == tail)
		{
			node *temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			curr = nullptr;
			delete(temp);
		}
		else
		{
			node *temp = curr;
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			curr = curr->next;
			delete(temp);
		}
		size--;
	}
	return;
}

//Removes the first item from the front
void sequence::remove_front()
{
	if (get_size() > 0)
	{
		node *temp = head;
		head = head->next;
		head->prev = nullptr;
		delete(temp);
	}
	return;
}

void sequence::operator +=(const sequence &other)
{
	node *othercursor = other.head;

	//Iterate through other and add all its elements into this
	while (othercursor != nullptr)
	{
		add_end(othercursor->data);
		othercursor = othercursor->next;
	}
}

sequence sequence::operator +(const sequence &other)
{
	sequence new_s;

	//Copy in sequences into new_s if they are within capacity combined
	if ((get_size() + other.get_size()) <= CAPACITY)
	{
		new_s += *this;
		new_s += other;
	}

	return new_s;
}


