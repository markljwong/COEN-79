#include <iostream>

using namespace std;

template <typename K, typename V>
class KeyedBag {
private:
	vector<pair<K, V>> data;
public:
	void insert(const K& key, cost V& value) {
		if(!contains(key)) data.push_back(pair<K, V>(key, value));
	}

	bool contains(const K& key) {
		for(int i = 0; i < data.size(); i++) 
			if (data[i].first == key) return true;
		return false;
	}

	const pair<K, V>& grab(const K& key) {
		for(int i = 0; i < data.size(); i++) 
			if (data[i].first == key) return data[i];
	}

	void delete(const K& key) {
		for(int i = 0; i < data.size(); i++) {
			if(data[i].first == key) 
				data.erase(vector<pair<K, V>>::iterator(data[i]));
		}

		//Other version of delete using the iterator
		for(vector<pair<K, V>>::iterator it = data.begin(); it!= data.end(); it++)
			if((*it).first == key)
				data.erase(it);
	}

	iterator begin() {
		iterator(data.begin());
	}

	iterator end() {
		iterator(data.end());
	}

	//Should only have the ++,--,*,+ and constructor
	class iterator {
	private: 
		vector<pair<K, V>>::iterator p;
	public:
		iterator(vector<pair<K, V>>::iterator x) {
			p = x;
		}

		iterator operator ++() { //pre
			p++;
			return p;
			//Alternatively
			return *this;
		}

		iterator operator ++(int i) { //post
			vector<pair<K, V>>::iterator save = p;
			p++;
			return save;
		}

		//Gets the pair within the vector at current p
		pair<K, V> operator *() {
			return *p;
		}
	}

	//From book iterator
	class iterator : public iterator<forward_iterator_tag, const K, const V> {

	}
}