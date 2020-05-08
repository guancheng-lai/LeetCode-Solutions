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
	int xLevel = -1, xParent;
	int yLevel = -1, yParent;
	
	void helperY(TreeNode* root, int target, int level) {
		if (root == nullptr) return;
		if (root->left)
		{
			if (root->left->val == target) 
			{
				yLevel = level;
				yParent = root->val;
				return;
			}
			else 
			{
				helperY(root->left, target, level+1);
			}
		}
		
		if (yLevel != -1) return;
		
		if (root->right)
		{
			if (root->right->val == target) 
			{
				yLevel = level;
				yParent = root->val;
				return;
			}
			else 
			{
				helperY(root->right, target, level+1);
			}
		}
	}
	
	void helperX(TreeNode* root, int target, int level) {
		if (root == nullptr) return;
		if (root->left)
		{
			if (root->left->val == target) 
			{
				xLevel = level;
				xParent = root->val;
			}
			else 
			{
				helperX(root->left, target, level+1);
			}
		}
		
		if (xLevel != -1) return;
		
		if (root->right)
		{
			if (root->right->val == target) 
			{
				xLevel = level;
				xParent = root->val;
			}
			else 
			{
				helperX(root->right, target, level+1);
			}
		}
	}
	
	bool isCousins(TreeNode* root, int x, int y) {
		if (root == nullptr) return false;
		helperX(root, x, 0);
		helperY(root, y, 0);
		return (xLevel == yLevel) && (xParent != yParent);
	}
};