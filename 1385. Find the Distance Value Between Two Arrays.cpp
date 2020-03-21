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
#include <limits>
#include <numeric>
using namespace std;

class Solution {
public:
	int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		int result(0);
		for (int i : arr1) {
			int count(0);
			
			for (int j : arr2) {
				if ( abs(i - j) > d ) {
					count++;
				}
				else {
					break;
				}
			}
			
			if (count == arr2.size()) {
				result++;
			}
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> arr1{4,5,8};
	vector<int> arr2{10,9,1,8};
	cout << s.findTheDistanceValue(arr1, arr2, 2);
}