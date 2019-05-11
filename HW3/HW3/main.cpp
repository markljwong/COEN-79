#include "bag.h"
#include "keyed_bag.h"
#include "set.h"
#include "sequence.h"
#include "circular_bag.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	string input;

	while (true) {
		cout << "Select which class to test by entering their number ... " << endl;
		cout << "[1] Delete Repetitions (Chapter 5: #2)" << endl;
		cout << "[2] Reverse Linked List (Chapter 5: #4)" << endl;
		cout << "[3] Sequence Class using Linked List (Chapter 5: #12 b)" << endl;
		cout << "[4] Keyed Bag Class using Linked List (Chapter 5: #12 e)" << endl;
		cout << "[5] Sequence Class using Linked List (Chapter 5: #15)" << endl;
		cout << "[6] Bag Class using Circularly Linked List (Chapter 5: #17)" << endl;
		cout << "[E] Exit Program" << endl << endl;

		cout << "Selection: ";
		cin >> input;
		cout << endl;

		if (input.compare("1") == 0) {
			bag b;

			cout << "==================================" << endl;
			cout << "Begin Delete Reptition test: " << endl << endl;

			b.insert(1);
			b.insert(2);
			b.insert(2);
			b.insert(3);
			b.insert(3);
			b.insert(3);

			cout << "Attached value 1 to bag." << endl;
			cout << "Attached value 2 to bag." << endl;
			cout << "Attached value 2 to bag." << endl;
			cout << "Attached value 3 to bag." << endl;
			cout << "Attached value 3 to bag." << endl;
			cout << "Attached value 3 to bag." << endl << endl;

			cout << "Number of 1's: " << b.get_count(1) << endl;
			cout << "Number of 2's: " << b.get_count(2) << endl;
			cout << "Number of 3's: " << b.get_count(3) << endl << endl;

			cout << "Removed duplicate values from bag: " << b.remove_reps() << endl << endl;

			cout << "Number of 1's: " << b.get_count(1) << endl;
			cout << "Number of 2's: " << b.get_count(2) << endl;
			cout << "Number of 3's: " << b.get_count(3) << endl << endl;

			cout << "Delete Repitition test end." << endl;
			cout << "==================================" << endl << endl;
		}
		else if (input.compare("2") == 0) {
			bag b;

			cout << "==================================" << endl;
			cout << "Begin Reverse Linked List test: " << endl << endl;

			b.insert(1);
			b.insert(2);
			b.insert(3);
			b.insert(4);

			cout << "Attached value 1 to bag." << endl;
			cout << "Attached value 2 to bag." << endl;
			cout << "Attached value 3 to bag." << endl;
			cout << "Attached value 4 to bag." << endl << endl;

			b.print_list();

			b.reverse();
			cout << "Reversed Linked list" << endl << endl;

			b.print_list();

			cout << "Delete Repitition function test end." << endl;
			cout << "==================================" << endl << endl;

		}
		else if (input.compare("3") == 0) {
			set s;

			cout << "==================================" << endl;
			cout << "Begin Set Class using Linked List test: " << endl << endl;

			s.insert(1);
			s.insert(2);
			s.insert(3);

			cout << "Attached value 1 to set." << endl;
			cout << "Attached value 2 to set." << endl;
			cout << "Attached value 3 to set." << endl << endl;

			cout << "Note: -1 indicate out of range." << endl;
			cout << "Value at s[0] : " << s[0] << endl;
			cout << "Value at s[1] : " << s[1] << endl;
			cout << "Value at s[2] : " << s[2] << endl << endl;

			s.erase(2);
			cout << "Deleted value 2 from bag." << endl << endl;

			cout << "Value at s[0] : " << s[0] << endl;
			cout << "Value at s[1] : " << s[1] << endl;
			cout << "Value at s[2] : " << s[2] << endl << endl;

			cout << "Set Class using Linked List test end." << endl;
			cout << "==================================" << endl << endl;
		}
		else if (input.compare("4") == 0) {
			keyed_bag b;

			cout << "==================================" << endl;
			cout << "Begin Keyed Bag Class using Linked List test: " << endl << endl;

			b.insert(1, 0);
			b.insert(2, 1);
			b.insert(2, 2);
			b.insert(3, 3);
			b.insert(3, 4);
			b.insert(3, 5);

			cout << "Attached value 1 to bag with key 0." << endl;
			cout << "Attached value 2 to bag with key 1." << endl;
			cout << "Attached value 2 to bag with key 2." << endl;
			cout << "Attached value 3 to bag with key 3." << endl;
			cout << "Attached value 3 to bag with key 4." << endl;
			cout << "Attached value 3 to bag with key 5." << endl << endl;

			cout << "Contains key 2: " << b.contains(2) << endl;
			cout << "Contains key 5: " << b.contains(5) << endl;
			cout << "Contains key 6: " << b.contains(6) << endl << endl;

			b.erase(0);
			b.erase(2);

			cout << "Deleted value 1 from bag with key 0." << endl;
			cout << "Deleted value 2 from bag with key 2." << endl << endl;

			cout << "Contains key 2: " << b.contains(2) << endl;
			cout << "Contains key 5: " << b.contains(5) << endl;
			cout << "Contains key 6: " << b.contains(6) << endl << endl;

			cout << "Keyed Bag Class using Linked List test end." << endl;
			cout << "==================================" << endl << endl;
		}
		else if (input.compare("5") == 0) {
			sequence s;

			cout << "==================================" << endl;
			cout << "Begin Sequence Class using Linked List test: " << endl << endl;

			s.attach_back(1);
			s.attach_back(2);
			s.attach_back(3);
			s.attach_back(4);
			s.attach_back(5);

			cout << "Attached value 1 to back of set." << endl;
			cout << "Attached value 2 to back of set." << endl;
			cout << "Attached value 3 to back of set." << endl;
			cout << "Attached value 4 to back of set." << endl;
			cout << "Attached value 5 to back of set." << endl << endl;

			cout << "Note: -1 indicate out of range." << endl;
			cout << "Value at s[0] : " << s[0] << endl;
			cout << "Value at s[1] : " << s[1] << endl;
			cout << "Value at s[2] : " << s[2] << endl;
			cout << "Value at s[3] : " << s[3] << endl;
			cout << "Value at s[4] : " << s[4] << endl;
			cout << "Value at s[5] : " << s[5] << endl << endl;

			s.start();
			cout << "Began iteration" << endl;
			cout << "Value of current: " << s.get_current() << endl << endl;

			s.advance();
			cout << "Advanced iterator" << endl;
			cout << "Value of current: " << s.get_current() << endl << endl;

			s.advance();
			cout << "Advanced iterator" << endl;
			cout << "Value of current: " << s.get_current() << endl << endl;

			s.retreat();
			cout << "Retreated iterator" << endl;
			cout << "Value of current: " << s.get_current() << endl << endl;

			s.insert(6);
			cout << "Inserted value 6 before current" << endl;
			cout << "Value of current: " << s.get_current() << endl << endl;

			cout << "Value at s[0] : " << s[0] << endl;
			cout << "Value at s[1] : " << s[1] << endl;
			cout << "Value at s[2] : " << s[2] << endl;
			cout << "Value at s[3] : " << s[3] << endl;
			cout << "Value at s[4] : " << s[4] << endl;
			cout << "Value at s[5] : " << s[5] << endl << endl;

			s.remove_front();
			cout << "Removed value at head." << endl << endl;

			cout << "Value at s[0] : " << s[0] << endl;
			cout << "Value at s[1] : " << s[1] << endl;
			cout << "Value at s[2] : " << s[2] << endl;
			cout << "Value at s[3] : " << s[3] << endl;
			cout << "Value at s[4] : " << s[4] << endl;
			cout << "Value at s[5] : " << s[5] << endl << endl;

			cout << "Sequence Class using Linked List test end." << endl;
			cout << "==================================" << endl << endl;
		}
		else if (input.compare("6") == 0) {
		circular_bag b;

		cout << "==================================" << endl;
		cout << "Begin Bag Class using Circularly Linked List test: " << endl << endl;

		b.insert(1);
		b.insert(2);
		b.insert(2);
		b.insert(3);
		b.insert(3);
		b.insert(3);

		cout << "Attached value 1 to bag." << endl;
		cout << "Attached value 2 to bag." << endl;
		cout << "Attached value 2 to bag." << endl;
		cout << "Attached value 3 to bag." << endl;
		cout << "Attached value 3 to bag." << endl;
		cout << "Attached value 3 to bag." << endl << endl;

		b.print_list();

		cout << "Removed duplicate values from bag: " << b.remove_reps() << endl << endl;

		b.print_list();

		b.reverse();
		cout << "Reversed Linked list" << endl << endl;

		b.print_list();

		cout << "Bag Class using Circularly Linked List end." << endl;
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