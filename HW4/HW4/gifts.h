#ifndef GIFTS_H
#define GIFTS_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

template<typename X, typename Y>
class gifts {
public:
	//Add a person to the list
	void add_person(X person) {
		if (!contains(person)) {
			list<string> li;
			data.push_back(pair<string, list<string>>(person, li));
		}
	}

	//Add a gift to a person's list
	void add_gift(X person, X gift) {
		for (size_t i = 0; i < data.size(); i++) {
			if (data[i].first.compare(person) == 0) {
				data[i].second.push_back(gift);
			}
		}
	}

	//Remove a person from the list
	void erase(X person) {
		for (typename vector<pair<X, Y>>::iterator it = data.begin(); it != data.end(); ++it) {
			if ((*it).first.compare(person) == 0) {
				data.erase(it);
				return;
			}
		}
	}

	//Getters
	void list_persons() const {
		for (size_t i = 0; i < data.size(); i++) {
			cout << data[i].first << endl;
		}
	}

	void list_gifts(X person) const {
		for (size_t i = 0; i < data.size(); i++) {
			if (data[i].first.compare(person) == 0) {
				for (list<string>::const_iterator it = data[i].second.begin(); it != data[i].second.end(); it++) {
					cout << *it << endl;
				}
			}
		}
	}

	bool contains(const X& person) const {
		for (size_t i = 0; i < data.size(); i++) {
			if (data[i].first.compare(person) == 0) return true;
		}

		//If function reaches here, it isn't found
		return false;
	}

private:
	vector<pair<X, Y>> data;
};

#endif
