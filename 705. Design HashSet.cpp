class MyHashSet {
private:
	int maxSize = 100001;
	vector< set<int> > hashTable = vector< set<int> >(maxSize);
	
public:
	/** Initialize your data structure here. */
	MyHashSet() {}
	
	void add(int key) {  
		int idx = key % maxSize;
        if (hashTable[idx].find(key) == hashTable[idx].end()) {
            hashTable[idx].insert(key);
        }
	}
	
	void remove(int key) {        
		int idx = key % maxSize;
        hashTable[idx].erase(key);
	}
	
	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		int idx = key % maxSize;
		return hashTable[idx].size() > 0 && hashTable[idx].find(key) != hashTable[idx].end();
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

