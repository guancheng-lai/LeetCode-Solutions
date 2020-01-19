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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int getDepth(TreeNode * root) {
		if (root == nullptr) {
			return 0;
		}
		
		int left = getDepth(root->left);
		if (left == -1) { return -1; }
		
		int right = getDepth(root->right);
		if (right == -1) { return -1; }
		
		return ( abs(left - right) <= 1 ? std::max(left, right)+1: -1);
	}
	
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		return (getDepth(root) != -1);
	}
};
int main(int argc, char *argv[]) {
	TreeNode * root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->left->right = new TreeNode(2);
	
	Solution s;	
	if (s.isBalanced(root)) cout << "Height-Balanced";
	else cout << "Not Height-Balanced";
}