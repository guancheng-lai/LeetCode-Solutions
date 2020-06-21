#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string_view>
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
#include <condition_variable>
#include <future>
#include <fstream>
#include <memory>
#include <limits>
#include <numeric>
using namespace std;

class BrowserHistory {
public:
	vector<string> data;
	int curr;
	
	BrowserHistory(string homepage) {
		data.push_back(homepage);
		curr = 0;
	}
	
	void visit(string url) {
		// if (url == data[curr]) return;
		
		if (curr == data.size() - 1) {
			data.push_back(url);
			curr = data.size() - 1;
			return;
		}
		
		data.erase(data.begin() + curr + 1, data.end());
		data.push_back(url);
		curr = data.size() - 1;
	}
	
	string back(int steps) {
		// if (steps > curr) return data[0];
		
		curr -= steps;
		curr = std::max(curr, 0);
		return data[curr];
	}
	
	string forward(int steps) {
		// if (curr + steps >= data.size()) {
		//     curr = data.size() - 1;
		//     return data[curr];
		// }
		
		curr += steps;
		curr = std::min(curr, (int) data.size()-1);
		return data[curr];
	}
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main(int argc, char *argv[]) {
	BrowserHistory* browserHistory = new BrowserHistory("leetcode.com");
	browserHistory->visit("google.com");       // You are in "leetcode.com". Visit "google.com"
	browserHistory->visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
	browserHistory->visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
	browserHistory->back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
	browserHistory->back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
	browserHistory->forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
	browserHistory->visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
	browserHistory->forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
	browserHistory->back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
	browserHistory->back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
}