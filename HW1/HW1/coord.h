#ifndef COORD_H
#define COORD_H

class coord 
{
private:
	double x;
	double y;
	double z;

public:
	coord(double, double, double);

	//Mutators
	void shift_x(double);
	void shift_y(double);
	void shift_z(double);

	void rot_x(double);
	void rot_y(double);
	void rot_z(double);

	//Accessors
	double get_x() { return x; }
	double get_y() { return y; }
	double get_z() { return z; }
};

#endif