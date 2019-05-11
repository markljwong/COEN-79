#include "bag.h"

using namespace std;

//Constructor
bag::bag() 
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

//Destructor
bag::~bag() 
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

//Insert new_data into bag
void bag::insert(int new_data) 
{
	if (get_size() == 0) 
	{
		head = tail = new node(new_data);
	}
	else 
	{
		tail->next = new node(new_data, nullptr, tail);
		tail = tail->next;
	}
	size += 1;
}

//Attempts to remove one of given rm_data from bag
bool bag::erase_one(const value_type &rm_data)
{
	node *cursor = head;
	node *temp = nullptr;

	//If not empty list, iterate through linked list and find rm_data. If found, remove it and return
	if (get_size() != 0)
	{
		while (cursor != nullptr)
		{
			if (cursor->data == rm_data)
			{
				if(get_size() == 1)
				{
					temp = head;
					head = nullptr;
					delete(head);
					size--;
					return true;
				}
				else if (cursor == head)
				{
					temp = head;
					head = head->next;
					head->prev = nullptr;
					delete(temp);
					size--;
					return true;
				}
				else if (cursor == tail)
				{
					temp = tail;
					tail = tail->prev;
					tail->next = nullptr;
					delete(temp);
					size--;
					return true;
				}
				else
				{
					temp = cursor;
					cursor->prev->next = cursor->next;
					cursor->next->prev = cursor->prev;
					delete(temp);
					size--;
					return true;
				}
			}
			else
			{
				cursor = cursor->next;
			}
		}
	}
	 
	//If function reaches here, rm_data isn't found or empty list so just return false
	return false;
}

//Attempts to remove all of given rm_data from bag
bag::size_type bag::erase(const value_type &rm_data)
{
	node *cursor = head;
	node *temp = nullptr;

	size_type removed_count;

	//If not empty list, iterate through linked list and find rm_data. If found, remove it and return
	if (get_size() != 0)
	{
		while (cursor != nullptr)
		{
			if (cursor->data == rm_data)
			{
				if (get_size() == 1)
				{
					temp = head;
					head = nullptr;
					delete(head);
					size--;
					return removed_count;
				}
				else if (cursor == head)
				{
					temp = head;
					head = head->next;
					head->prev = nullptr;
					delete(temp);
					size--;
					removed_count++;
				}
				else if (cursor == tail)
				{
					temp = tail;
					tail = tail->prev;
					tail->next = nullptr;
					delete(temp);
					size--;
					removed_count++;
				}
				else
				{
					temp = cursor;
					cursor->prev->next = cursor->next;
					cursor->next->prev = cursor->prev;
					delete(temp);
					size--;
					removed_count++;
				}
			}
			else
			{
				cursor = cursor->next;
			}
		}
	}

	return removed_count;
}

void bag::operator +=(const bag &other)
{
	node *othercursor = other.head;

	//Iterate through other and add all its elements into this
	while (othercursor != nullptr)
	{
		insert(othercursor->data);
		othercursor = othercursor->next;
	}
}

bag bag::operator +(const bag &other)
{
	bag new_bag;

	//Copy in bags into new_bag if they are within capacity combined
	if ((get_size() + other.get_size()) <= CAPACITY)
	{
		new_bag += *this;
		new_bag += other;
	}

	return new_bag;
}

void bag::operator -=(const bag &other)
{
	//If both bags have items then actually remove, otherwise don't waste time
	if (other.size != 0 && size != 0)
	{
		node *othercursor = other.head;

		//Iterate through b2 and remove all its elements from b1 bag
		while (othercursor != nullptr)
		{
			erase_one(othercursor->data);
			othercursor = othercursor->next;
		}
	}
}

bag bag::operator -(const bag &other) 
{
	//Intialize new_bag to b1 bag
	bag new_bag;
	new_bag += *this;
	new_bag -= other;

	return new_bag;
}

bag::size_type bag::get_count(const value_type &value) const
{
	size_type count = 0;
	node *cursor = head;
	
	while (cursor != nullptr)
	{
		if (cursor->data == value) count++;
		cursor = cursor->next;
	}

	return count;
}