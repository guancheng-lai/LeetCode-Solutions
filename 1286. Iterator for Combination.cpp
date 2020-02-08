class CombinationIterator {
private:
	string characters;
	int combLen;
	vector<string> info;
	vector<string>::iterator it;
	bool firstCall;
	
	void constructCombinations(string &tmp, int pos) {
		if (tmp.size() == combLen) {
			info.push_back(tmp);
			return;
		}
		
		for (int i = pos + 1; i < characters.size(); ++i) {
			tmp.push_back(characters[i]);
			constructCombinations(tmp, i);
			tmp.pop_back();
		}
	}
	
public:
	CombinationIterator(string characters, int combinationLength) {
		this->characters = characters;
		this->combLen = combinationLength;
		this->firstCall = true;
		
		string tmp("");
		for (int i = 0; i < characters.size(); ++i) {
			tmp.push_back(characters.at(i));
			constructCombinations(tmp, i);
			tmp.pop_back();
		}
		
	}
	
	string next() {
		if (firstCall) { 
			it = info.begin(); 
			firstCall = false;
		}
		string result = *it;
		std::advance(it, 1);
		return result;
	}
	
	bool hasNext() {
		if (it == info.end()) return false;
		
		return true;
	}
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */