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

struct TreeNode {
	int val;
	TreeNode * left;	
	TreeNode * right;
	TreeNode(){}
	TreeNode(int v) : val(v){}
};

class Solution {
public:
	void preorder(TreeNode * root) {
		if (root == nullptr) {return;}
		
		cout << root->val << " ";
		preorder(root->left);
		preorder(root->right);
	}
	
	bool verifyPreorder(vector<int>& preorder) {
		int min = std::numeric_limits<int>::min();
		stack<int> stk;
		
		for (auto i : preorder) {
			if (i < min) { return false; }
			
			while (!stk.empty() && i > stk.top()) {
				int curMin = stk.top(); stk.pop();
				min = curMin;
			}
			
			stk.push(i);
		}
		
		return true;
	}
};

int main(int argc, char *argv[]) {
	TreeNode * r = new TreeNode (100);
	r->left = new TreeNode (50);
	r->left->left = new TreeNode (25);
	r->left->right = new TreeNode (75);
	r->right = new TreeNode (150);
	r->right->left = new TreeNode (125);
	r->right->right = new TreeNode (300);
	
	vector<int> pre {100, 50, 25, 75, 150, 125, 300 };
	Solution solution;
	solution.preorder(r);
	cout << "Preorder: ";
	for (auto i : pre) { 
		cout << i << " ";
	}
	
	if (solution.verifyPreorder(pre)) {
		cout << "\nCorrect\n";
	}
}