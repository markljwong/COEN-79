#include "sequence.h"
#include <stdio.h>
#include <cassert>
#include <cmath>

void sequence::start() {
    if(size() > 0) {
        current_index = 0;
    }
}

void sequence::end() {
    if(size() > 0) {
        current_index = size()-1;
    }
}

void sequence::last() {
    current_index = CAPACITY-1;
}

sequence::value_type sequence::sequence::current() const {
    assert(is_item());
        
    return data[current_index];
}

void sequence::advance() {
    assert(is_item());
        
    if(current_index <= size()-1) {
        current_index++;
    }
}
void sequence::retreat() {
    if(current_index > 0 ) {
        current_index--;
    }
}

void sequence::insert(value_type new_data) {
    assert(size() < CAPACITY);
        
    if(size() > 0) {
        for(size_type i = size(); i > current_index; i--) {
            data[i] = data[i-1];
        }
    }
        
    data[current_index] = new_data;
    used++;
}

void sequence::attach(value_type new_data) {
    assert(size() < CAPACITY);
        
    if(size() > 0) {
        for(size_type i = size(); i > current_index+1; i--) {
            data[i] = data[i-1];
        }
		data[current_index + 1] = new_data;
    }
        
	data[current_index] = new_data;
    used++;
    current_index = current_index+1;
}

void sequence::remove_current() {
    assert(is_item());
        
    for(size_type i = current_index; i < size()-1; i++) {
        data[i-1] = data[i];
    }
        
    used--;
}

void sequence::insert_front(value_type new_data) {
    assert(size() < CAPACITY);
        
    if(size() > 0) {
        size_type i = size();
        do {
            data[i] = data[i-1];
            i--;
        }
        while(i > 0);
    }
        
    data[0] = new_data;
    used++;
    current_index = 0;
}

void sequence::attach_back(value_type new_data) {
    assert(size() < CAPACITY);
        
    data[size()] = new_data;
    used++;
    current_index = size()-1;
}

void sequence::remove_front() {
    start();
    assert(is_item());
        
    for(size_type i = 1; i < size(); i++) {
        data[i-1] = data[i];
    }
        
    used--;
}

//Getters
double sequence::mean() const {
    const sequence temp = *this;
    return summation(temp)/size();
}

double sequence::standardDeviation() const {
    double std_dev = 0;
        
    for(int i = 0; i < size(); i++) {
        std_dev += pow(data[i] - mean(), 2);
    }
        
    return sqrt(std_dev/size());
}

sequence::size_type sequence::size() const {
    return used;
}

bool sequence::is_item() const {
    return current_index <= size()-1;
}

void sequence::operator +=(const sequence &RHS) {
    assert(size() + RHS.size() < CAPACITY);
        
    for(size_type i = 0; i <= RHS.size() - 1; i++) {
        attach_back(RHS[i]);
    }
        
    current_index = size()-1;
}

sequence::value_type sequence::operator [](size_type index) const {
    assert(index < used);
        
    return data[index];
}

//Non-member functions
sequence::value_type summation(const sequence &s) {
    sequence::value_type sum = 0;
        
    for(int i = 0; i < s.size(); i++) {
        sum += s[i];
    }
        
    return sum;
}

sequence operator +(const sequence &LHS, const sequence &RHS) {
    sequence temp = LHS;
    temp += RHS;
    return temp;
}
