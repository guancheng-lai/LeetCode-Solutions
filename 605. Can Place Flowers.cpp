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
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {        
		if (n == 0) return true;
		size_t len = flowerbed.size();
		
		if (len == 1) {
			return flowerbed[0] == 0;
		}
		
		// Assign 2 to the array if we can`t put flower there
		if (flowerbed[0] == 1) { 
			flowerbed[1] = 2;
		}
		for (int i = 0; i < len; ++i) {
			if (flowerbed[i] == 1) {
				if (i < len - 1) flowerbed[i + 1] = 2;
				if (i > 1) flowerbed[i - 1] = 2;
			}
		}
		if (flowerbed[len - 1] == 1) { 
			flowerbed[len - 2] = 2; 
		}
		
		// Assigning new flower
		if (flowerbed[0] == 0 && flowerbed[1] != 1) {
			n--;
			flowerbed[0] = 1;
		}
		for (int i = 1; i < len - 1; ++i) {
			if (flowerbed[i] == 0) {
				if (flowerbed[i - 1] != 1 && flowerbed[i + 1] != 1) {
					n--;
					flowerbed[i] = 1;
				}
			}
		}
		if (flowerbed[len - 1] == 0 && flowerbed[len - 2] != 1) {
			n--;
		}
		
		return n <= 0;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> flowerbed { 1,0,0,0,1,0,0 };
	int n = 2;
	if (s.canPlaceFlowers(flowerbed, n)) {
		cout << "CAN PLACE FLOWERS\n";
	}
}