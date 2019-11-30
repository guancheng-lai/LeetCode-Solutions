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

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int maxLength = 0;
  
	int helper(TreeNode* root) {
		if (root == nullptr) { return 0; }
		int left = helper(root->left);
		int right = helper(root->right);
		maxLength = left + right > maxLength ? left + right : maxLength ;
		return 1 + (left > right ? left : right);
	}
	
public:
	int diameterOfBinaryTree(TreeNode* root) {
		helper(root);
		
		return maxLength;
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
	Solution solution;
	cout << solution.diameterOfBinaryTree(r);
}