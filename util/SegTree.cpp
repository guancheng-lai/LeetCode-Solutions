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

struct Vertex {
	int left, right;
	int sum = 0;
	Vertex *left_child = nullptr, *right_child = nullptr;

	Vertex(int lb, int rb) {
		left = lb;
		right = rb;
	}

	void extend() {
		if (!left_child && left + 1 < right) {
			int t = (left + right) / 2;
			left_child = new Vertex(left, t);
			right_child = new Vertex(t, right);
		}
	}

	void add(int k, int x) {
		extend();
		sum += x;
		if (left_child) {
			if (k < left_child->right)
				left_child->add(k, x);
			else
				right_child->add(k, x);
		}
	}

	int get_sum(int lq, int rq) {
		if (lq <= left && right <= rq)
			return sum;
		if (max(left, lq) >= min(right, rq))
			return 0;
		extend();
		return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
	}
};

int main(int argc, char *argv[]) {
	vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
	Vertex v(0,10);
	cout << v.get_sum(0,10);
	v.add(0,1);
	v.add(1,1);
	cout << v.get_sum(0,2);
	
//	v.add(0,-1);
//	cout << v.get_sum(0,1);
}