#include "statistician.h"

using namespace std;

//Constructor
statistician::statistician() 
{
	length = 0;
	last = 0;
	sum = 0;
	mean = 0;
	smallest = 0;
	largest = 0;
}

//Next number function
void statistician::next_number(double num) 
{
	//If first number, this is smallest and largest
	if (length == 0) 
	{
		smallest = num;
		largest = num;
	}
	else 
	{
		if (num < smallest) { smallest = num; }
		else if (num > largest) { largest = num; }
	}

	length++;
	last = num;
	sum += num;
	mean = sum / length;
}

//Add another statistician to this one
statistician statistician::operator +(const statistician &s2) {
	statistician new_stat;

	//Compare largest and smallest values and update accordingly
	if (this->smallest > s2.smallest) { new_stat.smallest = s2.smallest; }
	else { new_stat.smallest = this->smallest; }

	if (this->largest < s2.largest) { new_stat.largest = s2.largest; }
	else { new_stat.largest = this->largest; }

	new_stat.length = this->length + s2.length;
	new_stat.last = s2.last;
	new_stat.sum = this->sum + s2.sum;
	new_stat.mean = new_stat.sum / new_stat.length;

	return new_stat;
}
