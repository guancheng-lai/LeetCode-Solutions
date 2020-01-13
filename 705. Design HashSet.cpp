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

class MyHashSet {
private:
	vector<int> _info;
	
public:
	/** Initialize your data structure here. */
	MyHashSet() {

	}
	
	void add(int key) {
		if (key >= _info.size()) {
			_info.resize(key + 1, 0);
		}
		
		_info[key] = 1;
	}
	
	void remove(int key) {
		if (key < _info.size()) {
			_info[key] = 0;   
		}
	}
	
	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		return key < _info.size() && _info[key] == 1;
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(int argc, char *argv[]) {
	MyHashSet hashSet;//  = new MyHashSet();
	hashSet.add(1);         
	hashSet.add(2);         
	assert(hashSet.contains(1) == true); // returns true
	assert(hashSet.contains(3) == false);    // returns false (not found)
	hashSet.add(2);          
	assert(hashSet.contains(2) == true);    // returns true
	hashSet.remove(2);          
	assert(hashSet.contains(2) == false);    // returns false (already removed)
}