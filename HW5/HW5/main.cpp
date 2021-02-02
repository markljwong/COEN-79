#include "pqueue.h"
#include "minheap.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	string input;

	while (true) {
		cout << "Select which class to test by entering their number ... " << endl;
		cout << "[1] Priority Queue Class (Chapter 11: #1)" << endl;
		cout << "[2] Min Heap (Chapter 11: #5)" << endl;
		cout << "[E] Exit Program" << endl << endl;

		cout << "Selection: ";
		cin >> input;
		cout << endl;

		//Statistician class test code
		if (input.compare("1") == 0) {
			pqueue p;

			cout << "==================================" << endl;
			cout << "Priority Queue Class test: " << endl << endl;

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

			cout << "Priority Queue Class test end." << endl;
			cout << "==================================" << endl << endl;
		}

		//Set class test code
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