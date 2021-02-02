#include "bintree.h"
#include "minheap.h"
#include "minheap2.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	string input;

	while (true) {
		cout << "Select which class to test by entering their number ... " << endl;
		cout << "[1] Binary Tree Class (Chapter 10: #2)" << endl;
		cout << "[2] Complete Binary Tree (Chapter 11: #3)" << endl;
		cout << "[3] Incomplete Binary Tree (Chapter 11: #3)" << endl;
		cout << "[E] Exit Program" << endl << endl;

		cout << "Selection: ";
		cin >> input;
		cout << endl;

		//Binary Tree Class test code
		if (input.compare("1") == 0) {
			bintree<int> b;

			cout << "==================================" << endl;
			cout << "Binary Tree Class test: " << endl << endl;

			b.createFirstNode(1);
			b.addLeft(3);
			b.addRight(5);

			cout << "Created first node 1." << endl;
			cout << "Add left child 3." << endl;
			cout << "Add right child 5." << endl << endl;

			cout << "Current: " << b.retrieve() << endl << endl;

			b.shiftRight();
			cout << "Shifted to right child." << endl;
			cout << "Current: " << b.retrieve() << endl << endl;

			b.shiftUp();
			cout << "Shifted to parent." << endl;
			cout << "Current: " << b.retrieve() << endl << endl;

			b.shiftLeft();
			cout << "Shifted to left child." << endl;
			cout << "Current: " << b.retrieve() << endl << endl;

			cout << "Binary Tree Class test end." << endl;
			cout << "==================================" << endl << endl;
		}

		//Min Heap test code
		else if (input.compare("2") == 0) {
			minheap p;

			cout << "==================================" << endl;
			cout << "Min Heap test: " << endl << endl;

			p.push(1);
			p.push(2);
			p.push(3);
			p.push(2);

			cout << "Pushed value 1 to sequence." << endl;
			cout << "Pushed value 2 to sequence." << endl;
			cout << "Pushed value 3 to sequence." << endl;
			cout << "Pushed value 2 to sequence." << endl << endl;

			cout << "Popped: " << p.pop() << endl;
			cout << "Popped: " << p.pop() << endl;
			cout << "Popped: " << p.pop() << endl;
			cout << "Popped: " << p.pop() << endl << endl;

			cout << "Min Heap test end." << endl;
			cout << "==================================" << endl << endl;
		}

		//Incomplete Binary Tree test code
		else if (input.compare("3") == 0) {
			minheap2 b;

			cout << "==================================" << endl;
			cout << "Binary Tree Class test: " << endl << endl;

			b.createFirstNode(1);
			b.addLeft(3);
			b.addRight(5);

			cout << "Created first node 1." << endl;
			cout << "Add left child 3." << endl;
			cout << "Add right child 5." << endl << endl;

			cout << "Current: " << b.retrieve() << endl << endl;

			b.shiftRight();
			cout << "Shifted to right child." << endl;
			cout << "Current: " << b.retrieve() << endl << endl;

			b.shiftUp();
			cout << "Shifted to parent." << endl;
			cout << "Current: " << b.retrieve() << endl << endl;

			b.shiftLeft();
			cout << "Shifted to left child." << endl;
			cout << "Current: " << b.retrieve() << endl << endl;

			cout << "Binary Tree Class test end." << endl;
			cout << "==================================" << endl << endl;
		}

		else if (input.compare("E") == 0) {
			cout << "Exiting test program. Thank you" << endl;
			break;
		}
		else {
			cout << "Did not enter a valid selection. Check your selection." << endl << endl;
		}
	}

	return 0;
}