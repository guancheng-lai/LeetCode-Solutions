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

int numDecodings(string s) {
	if (s.size() == 0) return 0;			
	if (s[0] == '0') return 0;
	if (s.size() == 1) return 1;
				
	if (s.size() == 2) {
		if (s == "00") { return 0; }
		if (s == "01") { return 0; }				
		if (s[0] == '0' || s[1] == '0') { return 1; }
							
		if (stoi(s) > 26) { return 1; }
		else { return 2; }
	}
				
	if (stoi( s.substr(0,2) ) > 26) {
		int res = numDecodings(s.substr(2));
		if (res == 0) { return 0;}
																	
		return 1 + res;
	}
	else {
		if (s[0] == '0' && s[1] == '0' || s[1] == '0' && s[2] == '0') { return 0; }            
						
		if (s[0] == '0') { return numDecodings(s.substr(1)); }            
						
		if (s[1] == '0') { return numDecodings(s.substr(2)); }   
						
		int one = numDecodings(s.substr(1));
		// if (one == 0) {
		//     return 0;
		// }
						
		int two = numDecodings(s.substr(2));                   
		// if (two == 0) {
		//     return 0;
		// }

		return one + two;
	}
}
		
int main(int argc, char *argv[]) {
	cout << numDecodings("110");
}