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
private:
	int cnt = 1;
	
	void helper(TreeNode * root, int maxValue) {
		if (root == nullptr) return;
		if (root->val >= maxValue) cnt++,maxValue = root->val;
		
		helper(root->left, maxValue);
		helper(root->right, maxValue);
	}
	
public:
	int goodNodes(TreeNode* root) {
		helper(root->left, root->val);
		helper(root->right, root->val);
		return cnt;
	}
};