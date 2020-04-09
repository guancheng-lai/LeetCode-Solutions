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
	bool backspaceCompare(string S, string T) {
		int count(0);
		for (int i = S.size()-1; i >= 0; --i) {
			if (count == 0 && S[i] != '#') {
				continue;
			}
			
			if (S[i] == '#') {
				S.erase(S.begin() + i);
				count++;
				continue;
			}
			
			if (count == 0) continue;
			
			S.erase(S.begin() + i);
			count--;
		}
		
		count = 0;
		for (int i = T.size()-1; i >= 0; --i) {
			if (count == 0 && T[i] != '#') {
				continue;
			}
			
			if (T[i] == '#') {
				T.erase(T.begin() + i);
				count++;
				continue;
			}
			
			if (count == 0) continue;
			
			T.erase(T.begin() + i);
			count--;
		}
		
		return S == T;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
//	if (s.backspaceCompare("ab#c", "ad#c")) {
//	if (s.backspaceCompare("ab##", "c#d#")) {
//	if (s.backspaceCompare("a##c", "#a#c")) {
	if (s.backspaceCompare("a#c", "b")) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}
}