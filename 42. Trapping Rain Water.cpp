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

class Solution {
public:
	int trap(vector<int>& height) {
		size_t len = height.size();
		if (len <= 1) {
			return 0;
		}
		
		int leftIdx = 0, rightIdx = len - 1;
		int leftMax = 0, rightMax = 0;
		int result = 0;
		while (leftIdx != rightIdx) {
			if (height[leftIdx] <= height[rightIdx]) {
				if (height[leftIdx] > leftMax) { leftMax = height[leftIdx]; }
				else { result += (leftMax - height[leftIdx]); }
				leftIdx++;
			}
			else {
				if (height[rightIdx] > rightMax) { rightMax = height[rightIdx]; }
				else { result += (rightMax - height[rightIdx]); }
				rightIdx--;
			}
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution solution;
	vector<int> v {0,1,0,2,1,0,1,3,2,1,2,1};
	if (solution.trap(v) == 6) {
		cout << "Correct\n";
	}
}