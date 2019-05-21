template<typename T>
class sequence {
private:
	node *current;
	node *head;
	node *tail;
	int N;
public:

	class iterator {
	private:
		node *p;
	public:
		iterator(node *n) { p = n; }

		iterator operator --() { //pre
			p = p->prev;
			return iterator(p);
		}

		iterator operator --(int i) { //post
			node* temp = p;
			p = p->prev;
			return iterator(temp);
		}
	}
}