#ifndef STATISTICIAN_H
#define STATISTICIAN_H

class statistician 
{
private:
	double length;
	double last;
	double sum;
	double mean;
	double smallest;
	double largest;

public:
	statistician();

	//Operators
	statistician operator +(const statistician &);

	//Mutators
	void next_number(double);

	//Accessors
	double get_length() { return length; }
	double get_last() { return last; }
	double get_sum() { return sum; }
	double get_mean() { return mean; }
	double get_smallest() { return smallest; }
	double get_largest() { return largest; }
};

#endif