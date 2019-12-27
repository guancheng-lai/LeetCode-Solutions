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

template <typename T>
void printVector(const vector<T> &v) {
	cout << "\n-------------\nVECTOR: ";
	for (auto &i : v) {
		cout << i << " ";
	}
	cout << "\n-------------\n";
}
	
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0) return;
		if (m == 0) nums1 = nums2;
		
		int cur = m + n - 1;
		m--;
		n--;
		
		while (m >= 0 && n >= 0) {
			if (nums1[m] > nums2[n]) {
				nums1[cur--] = nums1[m--];
			}
			else {
				nums1[cur--] = nums2[n--];
			}
			
			// cout << "m=" << m << ",n=" << n << "\n";
		}

		if (m <= 0) {
			for (; n >= 0; n--) {
				nums1[n] = nums2[n];
			}
		}
		else {
			for (; m >= 0; m--) {
				nums1[m] = nums1[m];
			}
		}
	}
};

int main(int argc, char *argv[]) {
	vector<int> nums1{ 1,2,3,0,0,0 }; 
	int m = 3;
	vector<int> nums2{ 2,5,6 };
	int n = 3;
	
	Solution s;
	s.merge(nums1, m, nums2, n);
	printVector( nums1 );
}