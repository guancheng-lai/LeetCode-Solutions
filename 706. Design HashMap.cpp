#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>
#include <thread>
#include <mutex>
#include <fstream>
#include <memory>
using namespace std;

class MyHashMap {
private:
	vector<int> _info;
	
public:
	/** Initialize your data structure here. */
	MyHashMap() {
		
	}
	
	/** value will always be non-negative. */
	void put(int key, int value) {
		if (key >= _info.size()) {
			_info.resize(key + 1, -1);
		}   
		
		_info[key] = value;
	}
	
	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		return (key < _info.size() ? _info[key] : -1);
	}
	
	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		if (key < _info.size()) {
			_info[key] = -1;
		}
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(int argc, char *argv[]) {
	MyHashMap hashMap;
	hashMap.put(1, 1);          
	hashMap.put(2, 2);         
	assert(hashMap.get(1) == 1);            // returns 1
	assert(hashMap.get(3) == -1);            // returns -1 (not found)
	hashMap.put(2, 1);          // update the existing value
	assert(hashMap.get(2) == 1);            // returns 1 
	hashMap.remove(2);          // remove the mapping for 2
	assert(hashMap.get(2) == -1);            // returns -1 (not found) 
}