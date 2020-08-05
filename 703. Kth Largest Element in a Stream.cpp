class KthLargest {
public:
	int K;
	priority_queue<int, vector<int>, std::greater<int>> kth;
	
	KthLargest(int k, vector<int>& nums) {
		this->K = k;
		for (int num : nums) {
			if (kth.size() < k) {
				kth.push(num);
			} else if (num > kth.top()) {
				kth.pop();
				kth.push(num);
			}
		}
	}
	
	int add(int val) {
		if (kth.size() < K) {
			kth.push(val);
		} else if (val > kth.top()) {
			kth.pop();
			kth.push(val);
		}
		
		return kth.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */