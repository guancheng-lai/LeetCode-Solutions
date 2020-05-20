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
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int res = 0;
		for (int i = 0; i < startTime.size(); ++i)
		{
			if (startTime[i] <= queryTime && queryTime <= endTime[i]) 
			{
				res++;
			}
		}
		
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	
}