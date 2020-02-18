class ProductOfNumbers {
private:
	vector<int> info;
public:
	ProductOfNumbers() {
		
	}
	
	void add(int num) {
		info.push_back(num);
	}
	
	int getProduct(int k) {
		// for (int i = 0; i < info.size(); ++i) cout << info[i] << " " ;
		// cout << endl;
		
		int prod = 1;
		int stop = info.size() - k;
		for (int i = info.size() - 1; i >= stop; i--) {
			prod *= info[i];
		}
		
		return prod;
	}
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */