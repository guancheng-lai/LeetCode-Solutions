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
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         O(n^2)
//         map<int, int> indexs;
//         stack<int> stk;
//         for (int i = 0, end = nums2.size(); i < end; ++i) {
//             indexs[ nums2[i] ] = i;
//         }
		
//         vector<int> result(nums1.size());
//         for (int i = 0; i < nums1.size(); ++i) {
//             int nextMax = -1;
//             for (int j = indexs[ nums1[i] ] + 1; j < nums2.size(); ++j) {
//                 if (nums2[j] > nums1[i])
//                 {
//                     nextMax = nums2[j];
//                     break;
//                 }
//             }
			
//             result[i] = nextMax;
//         }
		
//         return result;
		
//         O(n)
		stack<int> smaller;
		vector<int> result(nums1.size());
		map<int, int> mp;
		
		for (auto i : nums2) {
			while (!smaller.empty() && smaller.top() < i) {
				int smallOne = smaller.top();
				smaller.pop();
				mp[smallOne] = i;
			}
			
			smaller.push(i);
		}
		
		for (int i = 0, end = nums1.size(); i != end; ++i) {
			if (mp.count( nums1[i] ) != 0) {
				result[i] =  mp[ nums1[i] ] ;
			}
			else {
				result[i] = -1;
			}
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution solution;
	vector<int> nums1 {4,1,2};
	vector<int> nums2 {1,3,4,2};
	vector<int> res = solution.nextGreaterElement(nums1, nums2);	
	vector<int> correct {-1,3,-1};
	if (res == correct) {
		cout << "Correct\n";
	}
}