#include "sequence.h"
#include "set.h"
#include "keyed_bag.h"
#include "sim_string.h"
#include "dynamic_set.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	string input;

	while (true) {
		cout << "Select which class to test by entering their number ... " << endl;
		cout << "[1] Sequence Class (Chapter 3: #4)" << endl;
		cout << "[2] Set Class (Chapter 3: #5)" << endl;
		cout << "[3] Keyed Bag Class (Chapter 3: #8)" << endl;
		cout << "[4] String Class (Chapter 4: #1)" << endl;
		cout << "[5] Dynamic Set Class (Chapter 4: #2b)" << endl;
		cout << "[E] Exit Program" << endl << endl;

		cout << "Selection: ";
		cin >> input;
		cout << endl;

		//Statistician class test code
		if (input.compare("1") == 0) {
			sequence s;

			cout << "==================================" << endl;
			cout << "Begin sequence class test: " << endl << endl;
		
			s.attach(1);
			s.attach(2);
			s.attach(3);

			cout << "Attached value 1 to sequence." << endl;
			cout << "Attached value 2 to sequence." << endl;
			cout << "Attached value 3 to sequence." << endl << endl;

			cout << "seq[0] = " << s[0] << endl;
			cout << "seq[1] = " << s[1] << endl;
			cout << "seq[2] = " << s[2] << endl << endl;

			cout << "Sequence class test end." << endl;
			cout << "==================================" << endl << endl;
		}

		//Set class test code
		else if (input.compare("2") == 0) {
			set s1;
			set s2;

			cout << "==================================" << endl;
			cout << "Begin set class test: " << endl << endl;

			s1.insert(1);
			s1.insert(2);
			s1.insert(3);

			s2.insert(1);

			cout << "Inserted value 1 to set 1." << endl;
			cout << "Inserted value 2 to set 1." << endl;
			cout << "Inserted value 3 to set 1." << endl << endl;

			cout << "Inserted value 1 to set 2." << endl << endl;

			cout << "Set 1 contains 1: " << s1.contains(1) << endl;
			cout << "Set 1 contains 2: " << s1.contains(2) << endl;
			cout << "Set 2 contains 4: " << s1.contains(4) << endl << endl;

			cout << "Set 2 contains 1: " << s2.contains(1) << endl << endl;

			s1.erase(2);
			s1 -= s2;

			cout << "Erased 2 from set 1" << endl;
			cout << "Erased set 2 from set 1" << endl << endl;

			cout << "Set 1 contains 1: " << s1.contains(1) << endl;
			cout << "Set 1 contains 2: " << s1.contains(2) << endl;
			cout << "Set 2 contains 4: " << s1.contains(4) << endl << endl;

			cout << "Set class test end." << endl;
			cout << "==================================" << endl << endl;
		}

		//Keyed bag class test code
		else if (input.compare("3") == 0) {
			keyed_bag b;

			cout << "==================================" << endl;
			cout << "Begin keyed bag class test: " << endl << endl;

			b.insert(1, 10);
			b.insert(2, 15);
			b.insert(2, 20);
			b.insert(3, 25);

			cout << "Inserted value 1 with key 10 to keyed bag." << endl;
			cout << "Inserted value 2 with key 15 to keyed bag." << endl;
			cout << "Inserted value 2 with key 20 to keyed bag." << endl;
			cout << "Inserted value 3 with key 25 to keyed bag." << endl << endl;

			cout << "Keyed bag contains key 10: " << b.contains(10) << endl;
			cout << "Keyed bag contains key 15: " << b.contains(15) << endl;
			cout << "Keyed bag contains key 20: " << b.contains(20) << endl;
			cout << "Keyed bag contains key 25: " << b.contains(20) << endl << endl;

			b.erase(20);

			cout << "Erased key 20 from keyed bag" << endl << endl;

			cout << "Keyed bag contains key 10: " << b.contains(10) << endl;
			cout << "Keyed bag contains key 15: " << b.contains(15) << endl;
			cout << "Keyed bag contains key 20: " << b.contains(20) << endl;
			cout << "Keyed bag contains key 25: " << b.contains(25) << endl << endl;

			cout << "Keyed bag class test end." << endl;
			cout << "==================================" << endl << endl;
		}

		//String class test code
		else if (input.compare("4") == 0) {
			sim_string s;
			sim_string s2;

			cout << "==================================" << endl;
			cout << "Begin string class test: " << endl << endl;

			cout << "Please enter your name: ";
			
			cin >> s;
			cout << endl;

			cout << "Your name: " << s << endl;

			cout << "Please enter your last name: ";

			cin >> s2;
			s2 += ", ";
			s.insert(s2, 0);

			cout << endl;

			cout << "Your name: " << s << endl << endl;

			cout << "Letter M found at: " << s.find('M') << endl << endl;

			cout << "String class test end." << endl;
			cout << "==================================" << endl << endl;
		}

		//Dyamic set test code
		else if (input.compare("5") == 0) {
			dynamic_set s;

			cout << "==================================" << endl;
			cout << "Begin dynamic set class test: " << endl << endl;

			s.insert(1);
			s.insert(2);
			s.insert(3);

			cout << "Inserted value 1 to set 1." << endl;
			cout << "Inserted value 2 to set 1." << endl;
			cout << "Inserted value 3 to set 1." << endl << endl;

			cout << "Length of set: " << s.get_size() << endl;
			cout << "Capacity of set: " << s.get_max_size() << endl;

			s.insert(4);
			s.insert(5);
			s.insert(6);

			cout << "Inserted value 4 to set 1." << endl;
			cout << "Inserted value 5 to set 1." << endl;
			cout << "Inserted value 6 to set 1." << endl << endl;

			cout << "Length of set: " << s.get_size() << endl;
			cout << "Capacity of set: " << s.get_max_size() << endl;

			cout << "Set class test end." << endl;
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