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
		bool checkIfExist(vector<int>& arr) {
			unordered_set<int> s;
			for (auto i : arr) {
				if ( s.count(i * 2) != 0 || ( i%2==0 && s.count(i/2) != 0) ) {
					return true;
				}
				
				s.insert(i);
			}
			
			return false;
			
	//         vector<int> pos, neg;
	//         for (auto i : arr) {
	//             if (i < 0) {
	//                 neg.push_back(i);
	//             }
	//             else {
	//                 pos.push_back(i);
	//             }
	//         }
			
	//         sort(pos.begin(), pos.end());
	//         sort(neg.begin(), neg.end());
			
	//         if (!pos.empty()){
	//             for (int i = 0; i < pos.size() - 1; ++i) { 
	//                 for (int j = i + 1; j < pos.size(); ++j) {
	//                     if (pos[i] * 2 == pos[j]) {
	//                         return true;
	//                     }   
	//                 }
	//             }
	//         }
			
	//         if (!neg.empty()){
	//             for (int i = neg.size() - 1; i > 0; i--) { 
	//                 for (int j = i - 1; j >= 0; j--) {
	//                     if (neg[i] * 2 == neg[j]) {
	//                         return true;
	//                     }   
	//                 }
	//             }
	//         }
	//         return false;
		}
	};

int main(int argc, char *argv[]) {
	vector<int> v{-16,-19,1};
	if (checkIfExist(v)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}