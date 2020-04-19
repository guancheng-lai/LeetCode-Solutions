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

class Solution {
private:
	int searchForPivot(vector<int> &nums) {
		int result;
		int start = 0, end = nums.size()-1;
		while (start <= end) {
			if (start == end) {
				result = start; 
				break;
			}
			int mid = (start+end+1)/2;

			if (nums[mid] > nums[0]) {
				start = mid+1;
			}
			else {
				if (nums[mid] < nums[mid-1]) {
					result = mid;
					break;	
				}
				else {
					end = mid-1;
				}               
			}
		}

		return result;
	}
	
	int searchForTarget(vector<int> &arr, int start, int end, int target) {
		int result = -1;
		while (start <= end) {
			int mid = (start+end+1)/2;
			if (arr[mid] == target) {
				result = mid;
				break;
			}
			else if (arr[mid] < target){
				start = mid+1;
			} 
			else {
				end = mid-1;
			}
		}
		if (start == end && arr[start] == target) result = start;
		return result;
	}
	
public:
	int search(vector<int>& nums, int target) {
		size_t len = nums.size();
		if (len == 0) {
			return -1;
		}
		if (len == 1) {
			return (target == nums[0] ? 0 : -1);
		}
		
		int pivotIdx = searchForPivot(nums);
		if (target == nums[pivotIdx]) {
			return pivotIdx;
		}
		cout << pivotIdx << endl;
		int result = -1;
		if (target < nums[0]) {
			result = searchForTarget(nums, pivotIdx, nums.size()-1, target);
		}
		else {
			result = searchForTarget(nums, 0, pivotIdx-1, target);
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> arr{1,3};
	cout << s.search(arr, 0);	
}