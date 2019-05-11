#include "sim_string.h"
#include <iostream>
#include <cstring>

using namespace std;

//Setters
void sim_string::insert(const sim_string& addend, int pos) {
	//If added length will be over allocated, then increase array size to fit new data
	if (length + addend.length >= allocated) {
		//Caclulate new memory allocation of array
		allocated = length + addend.length + INCREMENT;

		char* temp = new char[allocated];
		strcpy_s(temp, allocated, data);

		data = temp;
	}

	//Shift tail data back
	for (size_t i = allocated-1; i > pos; i--) {
		data[i] = data[i-addend.length];
	}

	//Add addend string data
	size_t i, j;
	for (i = 0, j = pos; i < addend.length; i++, j++) {
		data[j] = addend[i];
	}

	length = length + addend.length;
	data[length] = '\0';
}


void sim_string::operator +=(const sim_string& addend) {
	//If added length will be over allocated, then increase array size to fit new data
	if (length + addend.length >= allocated) {
		//Caclulate new memory allocation of array
		allocated = length + addend.length + INCREMENT;

		char* temp = new char[allocated];
		strcpy_s(temp, allocated, data);

		data = temp;
	}

	//Add addend string data
	size_t i, j;
	for (i = 0, j = length; i < addend.length; i++, j++) {
		data[j] = addend[i];
	}

	length = length + addend.length;
	data[length] = '\0';
}
void sim_string::operator +=(const char addend[]) {
	//If added length will be over allocated, then increase array size to fit new data
	if (length + strlen(addend) >= allocated) {
		//Caclulate new memory allocation of array
		allocated = length + strlen(addend) + INCREMENT;

		//Populate new area to clean out garbage already in there
		char* temp = new char[allocated];
		for (int i = 0; i < allocated; i++) { temp[i] = 0; }
		strcpy_s(temp, allocated, data);

		data = temp;
	}

	//Add addend string data
	size_t i, j;
	for (i = 0, j = length; i < strlen(addend); i++, j++) {
		data[j] = addend[i];
	}

	//Update length and data
	length = length + strlen(addend);
	data[length] = '\0';
}
void sim_string::operator +=(char addend) {
	//If added length will be over allocated, then increase array size to fit new data
	if (length + 2 >= allocated) {
		//Caclulate new memory allocation of array
		allocated =  length + 2 + INCREMENT;

		char* temp = new char[allocated];
		strcpy_s(temp, allocated, data);

		data = temp;
	}

	//Make a new char array temp with new memory allocation
	data[length] = addend;

	//Update length and data
	length = length + 1;
	data[length] = '\0';
}
void sim_string::reserve(size_t n) {
}

//Getters
size_t sim_string::get_length() const {
	return length;
}

char sim_string::operator [](size_t pos) const {
	return data[pos];
}

size_t sim_string::find(char c) const {
	for (size_t i = 0; i < length; i++) {
		if (data[i] == c) {
			return i;
		}
	}
}

//Comparitors
bool operator ==(const sim_string& LHS, const sim_string& RHS) {
	return (strcmp(LHS.data, RHS.data) == 0);
}
bool operator !=(const sim_string& LHS, const sim_string& RHS) {
	return (strcmp(LHS.data, RHS.data) != 0);
}
bool operator >=(const sim_string& LHS, const sim_string& RHS) {
	return (strcmp(LHS.data, RHS.data) > 0) || (strcmp(LHS.data, RHS.data) == 0);
}
bool operator <=(const sim_string& LHS, const sim_string& RHS) {
	return (strcmp(LHS.data, RHS.data) < 0) || (strcmp(LHS.data, RHS.data) == 0);
}
bool operator >(const sim_string& LHS, const sim_string& RHS) {
	return (strcmp(LHS.data, RHS.data) > 0);
}
bool operator <(const sim_string& LHS, const sim_string& RHS) {
	return (strcmp(LHS.data, RHS.data) < 0);
}

//Other operators
sim_string operator +(const sim_string& LHS, const sim_string& RHS) {
	sim_string new_string(LHS);
	new_string += RHS;

	return new_string;
}
istream& operator >>(istream& ins, sim_string& target) {
	char* temp = new char[20];

	ins >> temp;
	target += temp;

	return ins;
}
ostream& operator <<(ostream& outs, const sim_string& source) {
	outs << source.data;

	return outs;
}

//istream& getline(istream& ins, sim_string& target, char delimiter) {
//
//}
