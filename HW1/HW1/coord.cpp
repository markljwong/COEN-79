#include "coord.h"
#include <cmath>

using namespace std;

//Constructor
coord::coord(double x_val, double y_val, double z_val) 
{
	x = x_val;
	y = y_val;
	z = z_val;
}

//Shift functions
void coord::shift_x(double shift) { x += shift; }

void coord::shift_y(double shift) { y += shift; }

void coord::shift_z(double shift) { z += shift; }

//Rotation functions
void coord::rot_x(double angle) 
{
	y = y * cos(angle) - z * sin(angle);
	z = y * sin(angle) + z * cos(angle);
}

void coord::rot_y(double angle) 
{
	x = x * cos(angle) + z * sin(angle);
	z = -x * sin(angle) + z * cos(angle);
}

void coord::rot_z(double angle) 
{
	x = x * cos(angle) - y * sin(angle);
	y = x * sin(angle) + y * cos(angle);
}