#ifndef KEYED_BAG_PAIRS_H
#define KEYED_BAG_PAIRS_H

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

//V is the value type, K is key type, and S is the size type
template <typename V, typename K, typename S>
class keyed_bag_pairs {
public:
	class Iterator {
	public:
		Iterator(typename vector<pair<V, K>>::iterator n) {
			it = n;
		}

		Iterator operator ++() { //pre
			it++;
			return &it;
		}

		Iterator operator ++(int i) { //post
			typename vector<pair<V, K>>::iterator temp = it;
			it++;
			return temp;
		}

		pair<V, K> operator *() {
			return *it;
		}

		bool operator !=(const Iterator& other) {
			return it != other.it;
		}

	private:
		typename vector<pair<V, K>>::iterator it;
	};

	//Setters
	void insert(V new_data, K key) {
		if (!contains(key)) data.push_back(pair<V, K>(new_data, key));
	}

	void erase(K key) {
		for (typename vector<pair<V, K>>::iterator it = data.begin(); it != data.end(); ++it) {
			if ((*it).second == key) {
				data.erase(it);
				return;
			}
		}
	}

	//Getters
	bool contains(const K& key) const {
		for (size_t i = 0; i < data.size(); i++) {
			if (data[i].second == key) return true;
		}

		//If function reaches here, it isn't found
		return false;
	}

	const pair<V, K>& grab(const K& key) const {
		for (size_t i = 0; i < data.size(); i++) {
			if (data[i].second == key) return data[i];
		}
	}

	//Iterators
	Iterator begin() {
		return Iterator(data.begin());
	}
	Iterator end() {
		return Iterator(data.end());
	}

private:
	vector<pair<V, K>> data;
};

#endif
