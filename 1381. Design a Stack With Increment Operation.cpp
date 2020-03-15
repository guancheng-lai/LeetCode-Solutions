class CustomStack {
private:
	vector<int> stk;
	vector<int> add;
	int maxLen;
	
public:
	CustomStack(int maxSize) {
		this->maxLen = maxSize;
	}
	
	void push(int x) {
		if (stk.size() != maxLen) {
			stk.push_back(x);
			add.push_back(0);
		}
	}
	
	int pop() {
		if (stk.size() == 0) return -1;
		
		int result = stk.back(); stk.pop_back();
		int toAdd = add.back(); add.pop_back();
		
		result += toAdd;
		if (add.size() != 0) add.back() += toAdd;
		
		return result;
	}
	
	void increment(int k, int val) {
		if (add.size() == 0) return;
		
		add[ min(k-1,int(add.size()-1)) ] += val;
	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */