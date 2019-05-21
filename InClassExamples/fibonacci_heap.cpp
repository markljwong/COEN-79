#include <iostream>

using namespace std;

template<typename T>
class fibNode {
private:
	T _data;
	fibNode* _next;
	fibNode* _prev;
	fibNode* _parent;
	fibNode* _child;
	int degree;
	bool marked;

public:
	//Constructors
	fibnode(const T& da = T(), fibNode* n = NULL, fibNode* pr = NULL, fibNode* pa = NULL, fibNode* c = NULL, int de = 0, int m = false) {
		_data = da;
		_next = n;
		_prev = pr;
		_parent = pa;
		_child = c;
		degree = de;
		marked = m;
	}

	//Setters


	//Getters
	fibNode*& next() { return &_next; }
	fibNode*& prev() { return &_prev; }
	fibNode*& parent() { return &_parent; }
	fibNode*& child() { return &_child; }
}

template<typename T>
class fibHeap {
private:
	fibNode<T>* mHeap;
	int N;

	void clearHeap(fibNode<T>* p) {
		if(p) { 
			fibNode<T>* current = p;
			do {
				fibNode<T>* temp = current;
				current = current->next();
				clearHeap(temp->child());
				delete(temp);
			} while(current != p);
		}
	}

	void init() {
		mHeap = NULL;
		N = 0;
	}

	void copyHeap() {
		fibNode
	}

public:
	//Constructors
	fibHeap() {
		init();
	}

	~fibHeap() {
		clearHeap(m_heap);
	}

	fibHeap(const fibHeap& other) {
		init();
		m_heap = copyHeap(other.m_heap);
		N = other.N;
	}

	fibHeap* operator =(const fibHeap& RHS) { 
		if(this == &RHS) return *this;
		init();
		
		fibHeap copy(RHS);
		swap(mHeap, copy.mHeap);
		swap(N, copy.N);

		return *this;
	}


}