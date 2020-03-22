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

template <typename T1, typename T2>
void printMap(const map<T1, T2> &m) {
	cout << "\nMAP: ";
	for (auto &it : m) {
		cout << it.first << "=" << it.second << " ";
	}
	cout << "\n------------\n";
}

template <typename T>
void printStack(stack<T> s) {
	cout << "\nSTACK: TOP-> ";
	while (!s.empty()) {
		cout << s.top() << " "; s.pop();
	}
	cout << "-------------\n";
}

template <typename T1, typename T2>
void printStackOfPair(stack< pair<T1,T2> > s) {
	cout << "\nSTACK: TOP-> ";
	while (!s.empty()) {
		auto [t1, t2] = s.top(); s.pop();
		cout << t1 << "-" << t2 << " ";
	}
	cout << "->BOTTOM\n-------------\n";
}

template <typename T>
void printVector(const vector<T> &v) {
	cout << "\n-------------\nVECTOR: ";
	for (auto &i : v) {
		cout << i << " ";
	}
	cout << "\n-------------\n";
}

template <typename T>
void printList(const T& li) {
	cout << "\n-------------\nLIST: ";
	for (auto &i : li) {
		cout << i << " ";
	}
	cout << "\n-------------\n";
} 

template <typename T>
void printMatrix(const vector< vector<T> > &mat) {
	cout << "\n-------------\nMATRIX: ";
	for (auto &v : mat) {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << "\n-------------\n";
}

int main(int argc, char *argv[]) {
	
}