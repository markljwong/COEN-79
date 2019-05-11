#include "set.h"
#include "sequence.h"
#include "keyed_bag.h"
#include "keyed_bag_pairs.h"
#include "gifts.h"
#include <iostream>
#include <utility>
#include <iterator>
#include <string>

using namespace std;

int main() {
	string input;

	while (true) {
		cout << "Select which class to test by entering their number ... " << endl;
		cout << "[1] Template Set (Chapter 6: #2a)" << endl;
		cout << "[2] Template Sequence (Chapter 6: #2b)" << endl;
		cout << "[3] Template Keyed Bag (Chapter 6: #2e)" << endl;
		cout << "[4] Dynamic Pairs Array Keyed Bag with Iterator (Chapter 6: #4 & #5)" << endl;
		cout << "[5] Gift Class (Chapter 6: #8)" << endl;
		cout << "[6] Doubly Linked List Iterator  (Chapter 6: #9)" << endl;
		cout << "[E] Exit Program" << endl << endl;

		cout << "Selection: ";
		cin >> input;
		cout << endl;

		if (input.compare("1") == 0) {
			set<double, int> s;

			cout << "==================================" << endl;
			cout << "Begin Template Set test: " << endl << endl;

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

			cout << "Template Set end." << endl;
			cout << "==================================" << endl << endl;
		}
		else if (input.compare("2") == 0) {
			sequence<double, int> s;

			cout << "==================================" << endl;
			cout << "Begin Template Sequence test: " << endl << endl;

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

			cout << "Template Sequence test end." << endl;
			cout << "==================================" << endl << endl;
		}
		else if (input.compare("3") == 0) {
			keyed_bag<double, int, int> b;

			cout << "==================================" << endl;
			cout << "Begin Template Keyed Bag test: " << endl << endl;

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

			cout << "Template Keyed Bag test end." << endl;
			cout << "==================================" << endl << endl;
		}
		else if (input.compare("4") == 0) {
			keyed_bag_pairs<double, int, int> b;

			cout << "==================================" << endl;
			cout << "Dynamic Pairs Array Keyed Bag with Iterator test: " << endl << endl;

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

			cout << "Traversing through iterator:" << endl;
			for (keyed_bag_pairs<double, int, int>::Iterator it = b.begin(); it != b.end(); it++) {
				cout << "Value: " << (*it).first << "\t" << "Key: " << (*it).second << endl;
			}
			cout << endl;

			cout << "Dynamic Pairs Array Keyed Bag with Iterator test end." << endl;
			cout << "==================================" << endl << endl;
		}
		else if (input.compare("5") == 0) {
			gifts<string, list<string>> g;

			cout << "==================================" << endl;
			cout << "Begin Gift Class test: " << endl << endl;

			g.add_person("Mark");
			g.add_person("Ginny");
			g.add_person("Stanley");

			cout << "Added Mark to list" << endl;
			cout << "Added Ginny to list" << endl;
			cout << "Added Stanley to list" << endl << endl;

			cout << "People in the list:" << endl;
			g.list_persons();
			cout << endl;

			g.add_gift("Mark", "Computer");
			g.add_gift("Ginny", "Snacks");
			g.add_gift("Stanley", "Game");
			g.add_gift("Mark", "Book");

			cout << "Added Computer to Mark's gifts" << endl;
			cout << "Added Snacks to Ginny's gifts" << endl;
			cout << "Added Game to Stanley's gifts" << endl;
			cout << "Added Book to Mark's gifts" << endl << endl;
			
			g.erase("Stanley");
			cout << "Erased Stanley from list" << endl << endl;

			cout << "People in the list:" << endl;
			g.list_persons();
			cout << endl;

			cout << "Ginny's gifts: " << endl;
			g.list_gifts("Ginny");
			cout << endl;

			cout << "Mark's gifts: " << endl;
			g.list_gifts("Mark");
			cout << endl;

			cout << "Sequence Gift Class test end." << endl;
			cout << "==================================" << endl << endl;
		}
		else if (input.compare("6") == 0) {
			set<double, int> s;

			cout << "==================================" << endl;
			cout << "Begin Doubly Linked List Iterator test: " << endl << endl;

			s.insert(1);
			s.insert(2);
			s.insert(3);
			s.insert(4);

			cout << "Attached value 1 to set." << endl;
			cout << "Attached value 2 to set." << endl;
			cout << "Attached value 3 to set." << endl;
			cout << "Attached value 4 to set." << endl << endl;

			cout << "Print using iterator forwards" << endl;
			for (set<double, int>::Iterator it = s.begin(); it != nullptr; ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << "Print using iterator backwards" << endl;
			for (set<double, int>::Iterator it = s.end(); it != nullptr; --it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << "Doubly Linked List Iterator end." << endl;
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