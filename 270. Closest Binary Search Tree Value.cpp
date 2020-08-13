/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	double target;
	double minDiff = std::numeric_limits<double>::max();
	int minDiffNode = -1;
	
	void helper(TreeNode* root) {
		double currNodeVal = (double) root->val;
		double currDiff = std::abs(currNodeVal - target);
		if (currDiff < minDiff) {
			minDiff = currDiff;
			minDiffNode = root->val;
		}
		
		if (currNodeVal > target) {
			if (root->left) helper(root->left);
		} else {
			if (root->right) helper(root->right);
		}
	}
	
	int closestValue(TreeNode* root, double t) {
		this->target = t;
		helper(root);
		return minDiffNode;
	}
};