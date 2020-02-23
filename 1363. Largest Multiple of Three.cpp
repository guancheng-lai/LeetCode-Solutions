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
#include <condition_variable>
#include <future>
#include <fstream>
#include <memory>
using namespace std;

class Solution {
public:
	string largestMultipleOfThree(vector<int>& digits) {
		priority_queue<int, vector<int>, std::greater<int>> pq0, pq1, pq2;
		int sum(0);
		for (auto digit : digits) {
			sum += digit;
			if (digit % 3 == 0) { pq0.push(digit); }
			if (digit % 3 == 2) { pq2.push(digit); }  
			if (digit % 3 == 1) { pq1.push(digit); }
		}
		
		string result = "";
		if (sum == 0) return "0";
		
		
		if (sum % 3 == 0) {
			while (!pq0.empty()) {
				result+= to_string( pq0.top() );
				pq0.pop();
			}
			
			while (!pq1.empty()) {
				result+= to_string( pq1.top() );
				pq1.pop();
			}
			
			while (!pq2.empty()) {
				result+= to_string( pq2.top() );
				pq2.pop();
			}
			
			// cout << result << endl;
			
			sort(result.begin(), result.end());
			reverse(result.begin(), result.end());
			return result;
		}
		
		if (sum % 3 == 1) {
			if (pq1.size() > 0) {
				pq1.pop();
			}
			else if (pq2.size() > 1) {
				pq2.pop();
				pq2.pop();
			}
			else {
				return "";
			}
			
			
			while (!pq0.empty()) {
				result+= to_string( pq0.top() );
				pq0.pop();
			}
			
			while (!pq1.empty()) {
				result+= to_string( pq1.top() );
				pq1.pop();
			}
			
			while (!pq2.empty()) {
				result+= to_string( pq2.top() );
				pq2.pop();
			}
			
			// cout << result << endl;
			
			sort(result.begin(), result.end());
			reverse(result.begin(), result.end());
			return result;
		}
		
		if (sum % 3 == 2) {
			if (pq2.size() > 0) {
				pq2.pop();
			}
			else if (pq1.size() > 1) {
				pq1.pop();
				pq1.pop();
			}
			else {
				return "";
			}
			
			while (!pq0.empty()) {
				result+= to_string( pq0.top() );
				pq0.pop();
			}
			
			while (!pq1.empty()) {
				result+= to_string( pq1.top() );
				pq1.pop();
			}
			
			while (!pq2.empty()) {
				result+= to_string( pq2.top() );
				pq2.pop();
			}
			
			// cout << result << endl;
			
			sort(result.begin(), result.end());
			reverse(result.begin(), result.end());
			return result;
		}
		
		return "";
	}
};

int main(int argc, char *argv[]) {
	vector<int> vc{ 9,1,8 };
	Solution s;
	cout << s.largestMultipleOfThree(vc);	
	
}