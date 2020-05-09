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
	bool isPerfectSquare(int num) {
		if (num == 0) return false;
		
//         // Linear Scan      
//         for (unsigned long long i = 1; i * i < INT_MAX; ++i)
//         {
//             if (i*i == num) return true;    
//         }
		
//         return false;
		
//         // Binary Search
//         if (num == 1) return true;
//         unsigned long long left = 1, right = num/2;
//         while (left <= right)
//         {
//             if (left == right && left * left != num) return false;
//             unsigned long long mid = left + (right-left)/2;
//             unsigned long long guess = mid * mid;
//             if (guess == num) return true;
//             else if (mid * mid > num) 
//             {
//                 right = mid-1;
//             }
//             else 
//             {
//                 left = mid+1;
//             }
//         }
		
//         return false;
	
	// Newton
		if (num == 1)return true;
		unsigned long long i = num/2;
		while (i*i > num)
		{
			i = (i + num/i) / 2;
			cout << "i= " << i << ", num = " << num << endl;
		}
		
		return i * i == num;
	}
};

/*
1
2
3
4
5
32
16
63
64
65
127
128
129
*/

int main(int argc, char *argv[]) {
	Solution s;
	s.isPerfectSquare(2147483647);	
}