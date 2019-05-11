// HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "statistician.h"
#include "coord.h"
#include "bag.h"
#include "sequence.h"
#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string input;

	while (true)
	{
		cout << "Select which class to test by entering their number ... " << endl;
		cout << "[1] Statistician class (Chapter 2: #2 and #3)" << endl;
		cout << "[2] Coord Class (Chapter 2: #5)" << endl;
		cout << "[3] Bag Class (Chapter 3: #2)" << endl;
		cout << "[4] Sequence Class (Chapter 3: #3)" << endl;
		cout << "[E] Exit Program" << endl << endl;

		cout << "Selection: ";
		cin >> input;
		cout << endl;

		//Statistician class test code
		if (input.compare("1") == 0)
		{
			statistician s1;
			statistician s2;
			statistician s3;

			cout << "Begin statistician class test..." << endl << endl;

			while (true) 
			{
				cout << "Select which operation to perform by entering their number ... " << endl;
				cout << "[1] Edit statistican 1" << endl;
				cout << "[2] Edit statistician 2" << endl;
				cout << "[3] Show sum S1+S2" << endl;
				cout << "[E] Exit" << endl << endl;
				
				cout << "Selection: ";
				cin >> input;
				cout << endl;

				//Edit first statistician
				if (input.compare("1") == 0)
				{
					while (true)
					{
						cout << "[return] to return to previous menu. " << endl;
						cout << "[print] to show current values. " << endl;
						cout << "Command OR New Number (Double) for statistician 1: " << endl;
						cin >> input;
						cout << endl;

						//Show current values
						if (input.compare("print") == 0)
						{
							cout << endl;
							cout << "S1 Length: " << s1.get_length() << endl;
							cout << "S1 Last: " << s1.get_last() << endl;
							cout << "S1 Sum: " << s1.get_sum() << endl;
							cout << "S1 Mean: " << s1.get_mean() << endl;
							cout << "S1 Smallest: " << s1.get_smallest() << endl;
							cout << "S1 Largest: " << s1.get_largest() << endl << endl;
						}
						//Return to previous menu
						else if (input.compare("return") == 0)
						{
							cout << "Returning... " << endl << endl;
							break;
						}
						else
						{
							try
							{
								s1.next_number(stod(input));
								cout << "Added number " << input << endl << endl;
							}
							catch (...)
							{
								cout << "Did not enter a number or valid command." << endl << endl;
							}
						}
					}
				}
				//Edit second statistician
				else if (input.compare("2") == 0)
				{
					while (true)
					{
						cout << "[return] to continue to next step. " << endl;
						cout << "[print] to show current values. " << endl;
						cout << "Command OR New Number (Double) for statistician 2: ";
						cin >> input;
						cout << endl;

						//Show current values
						if (input.compare("print") == 0)
						{
							cout << endl;
							cout << "S2 Length: " << s2.get_length() << endl;
							cout << "S2 Last: " << s2.get_last() << endl;
							cout << "S2 Sum: " << s2.get_sum() << endl;
							cout << "S2 Mean: " << s2.get_mean() << endl;
							cout << "S2 Smallest: " << s2.get_smallest() << endl;
							cout << "S2 Largest: " << s2.get_largest() << endl << endl;
						}
						//Return to previous menu
						else if (input.compare("return") == 0)
						{
							cout << "Continuing... " << endl << endl;
							break;
						}
						else
						{
							try
							{
								s2.next_number(stod(input));
								cout << "Added number " << input << endl << endl;
							}
							catch (...)
							{
								cout << "Did not enter a number or valid command." << endl << endl;
							}
						}
					}
				}

				//Show the sum of S1 and S2
				else if (input.compare("3") == 0)
				{
					s3 = s1 + s2;

					cout << "S1 Length: " << s1.get_length() << endl;
					cout << "S1 Last: " << s1.get_last() << endl;
					cout << "S1 Sum: " << s1.get_sum() << endl;
					cout << "S1 Mean: " << s1.get_mean() << endl;
					cout << "S1 Smallest: " << s1.get_smallest() << endl;
					cout << "S1 Largest: " << s1.get_largest() << endl << endl;

					cout << "S2 Length: " << s2.get_length() << endl;
					cout << "S2 Last: " << s2.get_last() << endl;
					cout << "S2 Sum: " << s2.get_sum() << endl;
					cout << "S2 Mean: " << s2.get_mean() << endl;
					cout << "S2 Smallest: " << s2.get_smallest() << endl;
					cout << "S2 Largest: " << s2.get_largest() << endl << endl;

					cout << "S1+S2 Length: " << s3.get_length() << endl;
					cout << "S1+S2 Last: " << s3.get_last() << endl;
					cout << "S1+S2 Sum: " << s3.get_sum() << endl;
					cout << "S1+S2 Mean: " << s3.get_mean() << endl;
					cout << "S1+S2 Smallest: " << s3.get_smallest() << endl;
					cout << "S1+S2 Largest: " << s3.get_largest() << endl << endl;
				}
				else if (input.compare("E") == 0)
				{
					cout << "Statistician class test end." << endl << endl;
					break;
				}
				else
				{
					cout << "Did not enter a valid selection. Check your selection." << endl << endl;
				}		
			}

		}
		//Coord class test code
		else if (input.compare("2") == 0)
		{
			double x_val = 0;
			double y_val = 0;
			double z_val = 0;

			cout << "Begin coord class test..." << endl << endl;
			cout << "Enter value for X Coordinate: ";
			cin >> input;
			x_val = stod(input);
			cout << endl;

			cout << "Enter value for Y Coordinate: ";
			cin >> input;
			y_val = stod(input);
			cout << endl;

			cout << "Enter value for Z Coordinate: ";
			cin >> input;
			z_val = stod(input);
			cout << endl;

			//Create coord with given values
			coord cd(x_val, y_val, z_val);
			cout << "Coord created with (" << x_val << ", " << y_val << ", " << z_val << ")" << endl << endl;

			while (true) {
				cout << "Select which operation to perform by entering their number ... " << endl;
				cout << "[1] Shift X" << endl;
				cout << "[2] Shift Y" << endl;
				cout << "[3] Shift Z" << endl;
				cout << "[4] Rotate about X" << endl;
				cout << "[5] Rotate about Y" << endl;
				cout << "[6] Rotate about Z" << endl;
				cout << "[7] Print coordinates" << endl;
				cout << "[E] Exit" << endl << endl;

				cout << "Selection: ";
				cin >> input;
				cout << endl;

				if (input.compare("1") == 0) 
				{
					while (true) {
						try
						{
							cout << "Enter value for x shift: ";
							cin >> input;
							cd.shift_x(stod(input));
							cout << "X shifted by " << input << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter a number or valid command." << endl << endl;
						}
					}
				}
				else if (input.compare("2") == 0) 
				{
					while (true) {
						try
						{
							cout << "Enter value for y shift: ";
							cin >> input;
							cd.shift_y(stod(input));
							cout << "Y shifted by " << input << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter a number or valid command." << endl << endl;
						}
					}
				}
				else if (input.compare("3") == 0) 
				{
					while (true) {
						try
						{
							cout << "Enter value for z shift: ";
							cin >> input;
							cd.shift_z(stod(input));
							cout << "Z shifted by " << input << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter a number or valid command." << endl << endl;
						}
					}
				}
				else if (input.compare("4") == 0)
				{
					while (true) {
						try
						{
							cout << "Enter angle of rotation about x: ";
							cin >> input;
							cd.rot_x(stod(input));
							cout << "Rotated around x by " << input << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter a number or valid command." << endl << endl;
						}
					}

				}
				else if (input.compare("5") == 0) 
				{
					while (true) {
						try
						{
							cout << "Enter angle of rotation about y: ";
							cin >> input;
							cd.rot_y(stod(input));
							cout << "Rotated around y by " << input << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter a number or valid command." << endl << endl;
						}
					}
				}
				else if (input.compare("6") == 0) 
				{
					while (true) {
						try
						{
							cout << "Enter angle of rotation about z: ";
							cin >> input;
							cd.rot_z(stod(input));
							cout << "Rotated around z by " << input << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter a number or valid command." << endl << endl;
						}
					}
				}
				else if (input.compare("7") == 0) 
				{
					cout << "Coord currently at (" << cd.get_x() << ", " << cd.get_y() << ", " << cd.get_z() << ")" << endl << endl;
				}
				else if (input.compare("E") == 0)
				{
					cout << "Coord class test end." << endl << endl;
					break;
				}
				else
				{
					cout << "Did not enter a valid selection. Check your selection." << endl << endl;
				}
			}
		}
		//Bag class test code
		else if (input.compare("3") == 0)
		{
			bag b1;
			bag b2;
			bag b3;

			cout << "Begin bag class test..." << endl << endl;

			while (true)
			{
				cout << "Select which operation to perform by entering their number ... " << endl;
				cout << "[1] Add to bag 1" << endl;
				cout << "[2] Add to bag 2" << endl;
				cout << "[3] Remove one value from bag 1" << endl;
				cout << "[4] Remove one value from bag 2" << endl;
				cout << "[5] Remove all of one value from bag 1" << endl;
				cout << "[6] Remove all of one value from bag 2" << endl;
				cout << "[7] Remove bag 2 from bag 1 using - operator" << endl;
				cout << "[8] Remove bag 2 from bag 1 using -= operator" << endl;
				cout << "[9] Count a value" << endl;
				cout << "[E] Exit" << endl << endl;

				cout << "Selection: ";
				cin >> input;
				cout << endl;

				if (input.compare("1") == 0)
				{
					while (true) {
						try
						{
							cout << "Enter integer value to add to bag 1: ";
							cin >> input;
							b1.insert(stoi(input));
							cout << "Inserted to bag 1 integer " << input << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter an integer." << endl << endl;
						}
					}
				}
				else if (input.compare("2") == 0)
				{
					while (true) 
					{
						try
						{
							cout << "Enter integer value to add to bag 2: ";
							cin >> input;
							b2.insert(stoi(input));
							cout << "Inserted to bag 2 integer " << input << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter an integer." << endl << endl;
						}
					}
				}
				else if (input.compare("3") == 0)
				{
					while (true) 
					{
						try
						{
							cout << "Enter integer value to remove from bag 1: ";
							cin >> input;
							b1.erase_one(stoi(input));
							cout << "Removed from bag 1 integer " << input << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter an integer." << endl << endl;
						}
					}
				}
				else if (input.compare("4") == 0)
				{
					while (true) 
					{
						try
						{
							cout << "Enter integer value to remove from bag 2: ";
							cin >> input;
							b2.erase_one(stoi(input));
							cout << "Removed from bag 2 integer " << input << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter an integer." << endl << endl;
						}
					}
				}
				else if (input.compare("5") == 0)
				{
					while (true)
					{
						try
						{
							cout << "Enter integer value to remove ALL from bag 1: ";
							cin >> input;
							b1.erase(stoi(input));
							cout << "Removed from bag 2 integer " << input << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter an integer." << endl << endl;
						}
					}
				}
				else if (input.compare("6") == 0)
				{
					while (true)
					{
						try
						{
							cout << "Enter integer value to remove ALL from bag 2: ";
							cin >> input;
							b2.erase(stoi(input));
							cout << "Removed from bag 2 integer " << input << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter an integer." << endl << endl;
						}
					}
				}
				else if (input.compare("7") == 0)
				{
					b3 = b1 - b2;
					cout << "Removed b2 items from b1. Remaining items shown in b3. b1 unchanged." << endl << endl;
				}
				else if (input.compare("8") == 0)
				{
					b1 -= b2;
					cout << "Removed b2 items from b1. b1 is changed." << endl << endl;
				}
				else if (input.compare("9") == 0)
				{
					while (true)
					{
						try
						{
							cout << "Enter integer value to count: ";
							cin >> input;
							cout << "b1 count: " << b1.get_count(stoi(input)) << endl;
							cout << "b2 count: " << b2.get_count(stoi(input)) << endl;
							cout << "b3 count: " << b3.get_count(stoi(input)) << endl << endl;
							break;
						}
						catch (...)
						{
							cout << "Did not enter an integer." << endl << endl;
						}
					}
					
				}
				else if (input.compare("E") == 0)
				{
					cout << "Bag class test end." << endl << endl;
					break;
				}
				else
				{
					cout << "Did not enter a valid selection. Check your selection." << endl << endl;
				}
			}
		}
		//Sequence class test code
		else if (input.compare("4") == 0)
		{
			sequence s1;
			sequence s2;
			sequence s3;

			cout << "Begin sequence class test..." << endl << endl;

			while (true)
			{
				cout << "Select which operation to perform by entering their number ... " << endl;
				cout << "[1] Manipulate sequence 1" << endl;
				cout << "[2] Manipulate sequence 2" << endl;
				cout << "[3] Add sequence 2 to 1 using + operator" << endl;
				cout << "[4] Add sequence 2 to 1 using += operator" << endl;
				cout << "[5] Show sequences" << endl;
				cout << "[E] Exit" << endl << endl;

				cout << "Selection: ";
				cin >> input;
				cout << endl;

				if (input.compare("1") == 0)
				{
					while (true) {
						cout << "Select which operation to perform by entering their number ... " << endl;
						cout << "[1] Start iteration" << endl;
						cout << "[2] Advance iteration" << endl;
						cout << "[3] Get current value" << endl;
						cout << "[4] Go to end of sequence" << endl;
						cout << "[5] Insert new value before currrent" << endl;
						cout << "[6] Attach new value after current" << endl;
						cout << "[7] Attach new value to end of sequence" << endl;
						cout << "[8] Attach new value to start of sequence" << endl;
						cout << "[9] Remove current value" << endl;
						cout << "[10] Remove value from start of sequence" << endl;
						cout << "[E] Exit to previous" << endl << endl;

						cout << "Selection: ";
						cin >> input;
						cout << endl;

						if (input.compare("1") == 0)
						{
							if (s1.get_size() > 0)
							{
								s1.start();
								cout << "Began iteration." << endl << endl;
							}
							else
							{
								cout << "No items in sequence. Start iteration failed." << endl << endl;
							}
						}
						else if (input.compare("2") == 0)
						{
							if (s1.is_item())
							{
								s1.advance();
							}
							else
							{
								cout << "Current value is null. Try starting iteration." << endl << endl;
							}
						}
						else if (input.compare("3") == 0)
						{
							if (s1.is_item())
							{
								cout << "Current value is: " << s1.current() << endl << endl;
							}
							else
							{
								cout << "Current value is null. Try starting iteration." << endl << endl;
							}
						}
						else if (input.compare("4") == 0)
						{
							if (s1.get_size() > 0)
							{
								s1.move_to_end();
								cout << "Current set to end of sequence." << endl << endl;
							}
							else
							{
								cout << "No items in sequence. Request failed." << endl << endl;
							}
						}
						else if (input.compare("5") == 0)
						{
							try
							{
								cout << "Enter integer value to add before current: ";
								cin >> input;
								s1.insert(stoi(input));
								cout << "Added value: " << input << endl << endl;
							}
							catch (...)
							{
								cout << "Did not enter a valid integer." << endl << endl;
							}
						}
						else if (input.compare("6") == 0)
						{
							try
							{
								cout << "Enter integer value to add after current: ";
								cin >> input;
								s1.attach(stoi(input));
								cout << "Added value: " << input << endl << endl;
							}
							catch (...)
							{
								cout << "Did not enter a valid integer." << endl << endl;
							}
						}
						else if (input.compare("7") == 0)
						{
							try
							{
								cout << "Enter integer value to add to end: ";
								cin >> input;
								s1.add_end(stoi(input));
								cout << "Added value: " << input << endl << endl;
							}
							catch (...)
							{
								cout << "Did not enter a valid integer." << endl << endl;
							}
						}
						else if (input.compare("8") == 0)
						{
							try
							{
								cout << "Enter integer value to add to front: ";
								cin >> input;
								s1.add_front(stoi(input));
								cout << "Added value: " << input << endl << endl;
							}
							catch (...)
							{
								cout << "Did not enter a valid integer." << endl << endl;
							}
						}
						else if (input.compare("9") == 0)
						{
							try
							{
								s1.current();
								s1.remove_current();
								cout << "Removed current value." << input << endl << endl;
							}
							catch (...)
							{
								cout << "Current value is null. Try starting iteration." << endl << endl;
							}
						}
						else if (input.compare("10") == 0)
						{
							try
							{
								s1.current();
								s1.remove_front();
								cout << "Removed front value." << input << endl << endl;
							}
							catch (...)
							{
								cout << "Current value is null. Try starting iteration." << endl << endl;
							}
						}
						else if (input.compare("E") == 0)
						{
							break;
						}
						else
						{
							cout << "Did not enter a valid selection. Check your selection." << endl << endl;
						}
					}
				}
				else if (input.compare("2") == 0)
				{
					while (true) {
						cout << "Select which operation to perform by entering their number ... " << endl;
						cout << "[1] Start iteration" << endl;
						cout << "[2] Advance iteration" << endl;
						cout << "[3] Get current value" << endl;
						cout << "[4] Go to end of sequence" << endl;
						cout << "[5] Insert new value before currrent" << endl;
						cout << "[6] Attach new value after current" << endl;
						cout << "[7] Attach new value to end of sequence" << endl;
						cout << "[8] Attach new value to start of sequence" << endl;
						cout << "[9] Remove current value" << endl;
						cout << "[10] Remove value from start of sequence" << endl;
						cout << "[E] Exit to previous" << endl << endl;

						cout << "Selection: ";
						cin >> input;
						cout << endl;

						if (input.compare("1") == 0)
						{
							if (s2.get_size() > 0)
							{
								s2.start();
								cout << "Began iteration." << endl << endl;
							}
							else
							{
								cout << "No items in sequence. Start iteration failed." << endl << endl;
							}
						}
						else if (input.compare("2") == 0)
						{
							if (s2.is_item())
							{
								s2.advance();
							}
							else
							{
								cout << "Current value is null. Try starting iteration." << endl << endl;
							}
						}
						else if (input.compare("3") == 0)
						{
							if (s2.is_item())
							{
								cout << "Current value is: " << s2.current() << endl << endl;
							}
							else
							{
								cout << "Current value is null. Try starting iteration." << endl << endl;
							}
						}
						else if (input.compare("4") == 0)
						{
							if (s2.get_size() > 0)
							{
								s2.move_to_end();
								cout << "Current set to end of sequence." << endl << endl;
							}
							else
							{
								cout << "No items in sequence. Request failed." << endl << endl;
							}
						}
						else if (input.compare("5") == 0)
						{
							try
							{
								cout << "Enter integer value to add before current: ";
								cin >> input;
								s2.insert(stoi(input));
								cout << "Added value: " << input << endl << endl;
							}
							catch (...)
							{
								cout << "Did not enter a valid integer." << endl << endl;
							}
						}
						else if (input.compare("6") == 0)
						{
							try
							{
								cout << "Enter integer value to add after current: ";
								cin >> input;
								s2.attach(stoi(input));
								cout << "Added value: " << input << endl << endl;
							}
							catch (...)
							{
								cout << "Did not enter a valid integer." << endl << endl;
							}
						}
						else if (input.compare("7") == 0)
						{
							try
							{
								cout << "Enter integer value to add to end: ";
								cin >> input;
								s2.add_end(stoi(input));
								cout << "Added value: " << input << endl << endl;
							}
							catch (...)
							{
								cout << "Did not enter a valid integer." << endl << endl;
							}
						}
						else if (input.compare("8") == 0)
						{
							try
							{
								cout << "Enter integer value to add to front: ";
								cin >> input;
								s2.add_front(stoi(input));
								cout << "Added value: " << input << endl << endl;
							}
							catch (...)
							{
								cout << "Did not enter a valid integer." << endl << endl;
							}
						}
						else if (input.compare("9") == 0)
						{
							try
							{
								s2.current();
								s2.remove_current();
								cout << "Removed current value." << input << endl << endl;
							}
							catch (...)
							{
								cout << "Current value is null. Try starting iteration." << endl << endl;
							}
						}
						else if (input.compare("10") == 0)
						{
							try
							{
								s2.current();
								s2.remove_front();
								cout << "Removed front value." << input << endl << endl;
							}
							catch (...)
							{
								cout << "Current value is null. Try starting iteration." << endl << endl;
							}
						}
						else if (input.compare("E") == 0)
						{
							break;
						}
						else
						{
							cout << "Did not enter a valid selection. Check your selection." << endl << endl;
						}
					}
				}
				else if (input.compare("3") == 0)
				{
					s3 = s1 + s2;
					cout << "Added s2 to s1. Items shown in s3. s1 unchanged." << endl << endl;
				}
				else if (input.compare("4") == 0)
				{
					s1 += s2;
					cout << "Added s2 to s1. s1 is changed." << endl << endl;
				}
				else if (input.compare("5") == 0)
				{
					s1.start();
					cout << "s1 values: ";
					while (s1.is_item())
					{
						cout << s1.current() << ", ";
						s1.advance();
					}

					cout << endl << endl;
					s2.start();
					cout << "s2 values: ";
					while (s2.is_item())
					{
						cout << s2.current() << ", ";
						s2.advance();
					}

					cout << endl << endl;
					s3.start();
					cout << "s3 values: ";
					while (s3.is_item())
					{
						cout << s3.current() << ", ";
						s3.advance();
					}

					cout << endl << endl;
				}
				else if (input.compare("E") == 0)
				{
					cout << "Sequence class test end." << endl << endl;
					break;
				}
				else
				{
					cout << "Did not enter a valid selection. Check your selection." << endl << endl;
				}
			}
		}
		//Exit Program
		else if (input.compare("E") == 0)
		{
			cout << "Thank you for using this test program. Exiting." << endl;
			break;
		}
		else
		{
			cout << "Did not enter a valid selection. Check your selection." << endl << endl;
		}
	}
}
