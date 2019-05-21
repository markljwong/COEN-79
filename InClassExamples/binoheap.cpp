//Binomial Tree
//- Follows min heap properties

#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class binoheap {
public:
	void push_back(T data) {

	}

	void clear();	

	node* merge_tree(node* &LHS, node* &RHS) {
		if(!LHS) return RHS;
		if(!RHS) return LHS;

		//Swap data if LHS data is bigger than RHS data
		if(LHS->get_data() > RHS->get_data()) {
			swap(LHS, RHS); //swap from std
		}

		//Only have to connect sibling, don't have to care about cousins
		RHS->set_sibling(LHS->child);
		LHS->set_child(RHS);

		return LHS:
	}

	vector<node<T>*> merge_heap(typename vector<node<T>*> &LHS, typename vector<node<T>*> &RHS) {
		typename vector<node<T>*> result;

		int max = max(LHS.get_size(), RHS.get_size());
		LHS.resize(max);
		RHS.resise(max);

		typename node<T>* carry = NULL;
		for(int i = 0; i < max; i++) {
			typename vector<node<T>*> temp;
			if(carry) temp.push_back(carry);
			if(LHS[i])temp.push_back(LHS[i]);
			if(RHS[i])temp.push_back(RHS[i]);

			if(temp.get_size() == 0) {
				result.push_back(temp[0])
				carry = NULL;
			} else if(temp.size() == 1) {
				result.push_back(temp[0])
				carry = NULL;
			} else if (temp.size() == 2) {
				result.push_back(NULL);
				carry = merge_tree(temp[0], temp[1]);
			} else {
				result.push_back(temp[2]);
				carry = merge_tree(temp[0], temp[1]);
			}
		}

		if(carry) result.push_back(carry);
		LHS = result;
		RHS.clear();
	}

	void push(const T &data) {
		typename vector<node<T>*> new_heap;
		new_heap = push_back(new node(x));
		merg_heap(this->min_heap, newHeap);
		N++;
	}

	void pop() {
		typename vector<node<T>*>::iterator min = min_element(min_heap.begin(), min_heap.end(), compareNode<T>);
		typename vector<node<T>*> children;

		for(node<T>* child = (*min).get_child(); child != NULL; child = child->get_sibling())
			children.push_back(child);

		reverse(child.begin(), children.end());

		for(int i = 0; i < children.size(); i++) 
			children[i].set_sibling(NULL);

		delete *min;
		*min = NULL;
		N--;

		if(min == min_heap.end()-1) min_heap.pop_back();

		merge_heap(min_heap, children);
	}

	T top() {
		assert(get_size() > 0);
		typename vector<node<T>*>::iterator min = min_element(min_heap.begin(), min_heap.end(), compareNode<T>);

		return (*min)->get_data();
	}

	//Getters
	int get_size() { return N; }

private:
	int N;
	vector<node<T>*> min_heap;
}


template<typename T>
class node {
private:
	node* child;
	node* sibling;

	T data;
public:
	//Mutators
	void set_child(node* n) { left_child = n; }
	void set_sibling(node* n) { sibling = n; }

	//Accessors
	node*& child() { return left_child; }
	node*& sibling() { return sibling; }
	T get_data() { return data; }
}

