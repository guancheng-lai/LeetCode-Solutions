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
	int maxArea(vector<int>& height) {
		if (height.size() <= 1) return 0;
		
		int left = 0, right = height.size() - 1;
		
		int result(0);
		while (left != right) {
			int currVolumn;
			
			if (height[left] > height[right]) {
				currVolumn = height[right] * (right - left);
			}
			else {
				currVolumn = height[left] * (right - left);
			}

			if (currVolumn > result) { result = currVolumn; }
			
			// cout << currVolumn << " " << result << endl;
			
			if (height[left] > height[right]) {
				right--;
			}
			else {
				left++;
			}
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> v{ 1,8,6,2,5,4,8,3,7 };
	assert(s.maxArea(v) == 49);
}