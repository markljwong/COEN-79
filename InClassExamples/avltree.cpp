// Adelson-Velskii and Landis Tree (AVL tree)
// ==========================================
void rotateWithLeftChild(Node*& k2) {
	Node* k1 = k2->left();
	ks->right = k1->right();
	k1->right = k2;
	k2 = k1;
}

void rotateWithRightChild(Node*& k2)  {
	Node* k1 = k2->right();
	ks->left = k1->left();
	k1->left = k2;
	k2 = k1;
}

void doubleWithLeftChild(Node*& k2) {
	rotateWithLeftChild(k2->left());
	rotateWithLeftChild(k2);
}

void doubleWithRightCHild(Node*& k2) {
	rotateWithRightChild(k2->right());
	rotateWithRightChild(k2);
}

void insert(const T& x, Node*& ptr) {
	if(ptr == NULL) {
		ptr = new Node(x);
	}
	else if (x < ptr->data()) {
		insert (x, ptr->left());
		if(height(ptr->left()) - height(ptr->right()) == 2) {
			if(x < ptr->left()->data())
				rotateWithLeftChild(ptr);
			else 
				doubleWithLeftChild(ptr);
		}
	}
	else if (ptr->data() < x) {
		insert(x, ptr->right());
		if(height(ptr->right()) - height(ptr->left()) == 2) {
			if(x < ptr->right()->data());
				rotateWithRightChild(ptr);
			else 
				doubleWithRightChild(ptr);
		}
	}
}

void remove(const T& x, Node*& ptr) {
	if(ptr == NULL) 
		return;
	if(x < ptr->data()) {
		remove(x, ptr->left());
		if(height(ptr->right()) - height(ptr->left() == 2)) {
			if(x < ptr->left()->data())
				doubleWithRightChild(ptr);
			else
				rotateWithRightChild(ptr);
		}
	}
	else if(ptr->data() < x) {
		remove(x, ptr->right);
		if(height(ptr->left()) - height(ptr->right() == 2)) {
			if(x <ptr->right()->data())
				doubleWithLeftChild(ptr);
			else
				rotateWithLeftChild(ptr);
		}
	}
	else if(ptr->left() != NULL && ptr->right() != NULL) {
		ptr->data() = findMin(ptr->right())->data();
		remove(ptr->data(), ptr->right());
		if(height(ptr->left()) - height(ptr->right()) == 2) {
			if(height(ptr->left()->left()) > height(ptr->left()->right())) 
				rotateWithLeftChild(ptr);
			else
				rotateWithLeftChild(ptr);
		}
	}
	else {
		Node* old_ptr = ptr;
		ptr = (ptr->left() != NULL) ? ptr->left() : ptr->right();
		delete(oldptr);
	}
}


//rotateWithLeftChild
//			k1
//	k1 				z
//x 	y 

//doubleWithRightChild
//			k3
//	z				k2
//				k1		x
//			y2	y1

