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


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int myMax(int a, int b, int c) {
		if (a >= b && a >= c) {
			return a;
		}
		
		if (b >= a && b >= c) {
			return b;
		}
			
		return c;
	}
	
	int helper(TreeNode * root, int minValue, int maxValue) {
		if (root->val < minValue) {
			minValue = root->val;   
		}
		else if (maxValue < root->val) {
			maxValue = root->val;   
		}

		int myDiff = std::max(abs(minValue - root->val), abs(maxValue - root->val));
		// cout << myDiff << " ";
		int leftDiff = 0, rightDiff = 0;
		if (root->left != nullptr) leftDiff = helper(root->left, minValue, maxValue);
		if (root->right != nullptr) rightDiff = helper(root->right, minValue, maxValue);
		
		return myMax(myDiff, leftDiff, rightDiff);
	}
	
public:
	int maxAncestorDiff(TreeNode* root) {
		return helper(root, root->val, root->val);
	}
};

int main(int argc, char *argv[]) {
	Solution solution;
	solution.maxAncestorDiff(r);
	
	TreeNode * r = new TreeNode(8);
	r->left = new TreeNode(3);
	r->left = new TreeNode(3);
}