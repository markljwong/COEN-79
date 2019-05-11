#ifndef SIM_STRING_H
#define SIM_STRING_H

#include <iostream>
#include <cstring>

using namespace std;

class sim_string {
public:
	static const size_t INCREMENT = 4;

	//Constructors
	sim_string(const char str[] = "") {
		length = strlen(str);
		allocated = length + 5;
		data = new char[allocated];
		for (int i = 0; i < allocated; i++) { data[i] = 0; }
		strcpy_s(data, allocated, str);
	}

	sim_string(char c) {
		length = 1;
		allocated = length + 5;
		data = new char[allocated];
		for (int i = 0; i < allocated; i++) { data[i] = 0; }
		data[0] = c;
	}

	sim_string(const sim_string& other) {
		length = other.length;
		allocated = length + 5;
		data = new char[allocated];
		for (int i = 0; i < allocated; i++) { data[i] = 0; }
		strcpy_s(data, allocated, other.data);
	}

	~sim_string() {
		delete[] data;
	}

	//Setters
	void insert(const sim_string& addend, int pos);

	void operator +=(const sim_string& addend);
	void operator +=(const char addend[]);
	void operator +=(char addend);
	void reserve(size_t n);

	//Getters
	size_t get_length() const;
	char operator [](size_t pos) const;
	size_t find(char c) const;

	//Friends
	friend bool operator ==(const sim_string& LHS, const sim_string& RHS);
	friend bool operator !=(const sim_string& LHS, const sim_string& RHS);
	friend bool operator >=(const sim_string& LHS, const sim_string& RHS);
	friend bool operator <=(const sim_string& LHS, const sim_string& RHS);
	friend bool operator >(const sim_string& LHS, const sim_string& RHS);
	friend bool operator <(const sim_string& LHS, const sim_string& RHS);

	friend istream& operator >>(istream& ins, sim_string& target);
	friend ostream& operator <<(ostream& outs, const sim_string& source);
	
private:
	char *data;
	size_t allocated;
	size_t length;
};

//Comparitors
bool operator ==(const sim_string& LHS, const sim_string& RHS);
bool operator !=(const sim_string& LHS, const sim_string& RHS);
bool operator >=(const sim_string& LHS, const sim_string& RHS);
bool operator <=(const sim_string& LHS, const sim_string& RHS);
bool operator >(const sim_string& LHS, const sim_string& RHS);
bool operator <(const sim_string& LHS, const sim_string& RHS);

//Other operators
sim_string operator +(const sim_string& LHS, const sim_string& RHS);
istream& operator >>(istream& ins, sim_string& target);
ostream& operator <<(ostream& outs, const sim_string& source);
//istream& getline(istream& ins, sim_string& target, char delimiter = '\n');

#endif
