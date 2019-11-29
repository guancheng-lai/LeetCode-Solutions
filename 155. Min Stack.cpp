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
class MinStack {
private:
	std::stack<int> data;
	std::stack<int> minData;
	
public:
	/* initialize your data structure here. */
	MinStack() {
		data = stack<int>();
		minData = stack<int>();
	}
	
	void push(int x) {
		if (minData.empty() || x <= minData.top()) {
			minData.push(x);
		}
		
		data.push(x);
	}
	
	void pop() {
		if (data.top() == minData.top()) {
			data.pop();
			minData.pop();
		}
		else {
			data.pop();
		}
	}
	
	int top() {
		return data.top();
	}
	
	int getMin() {
		return minData.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char *argv[]) {
	
}