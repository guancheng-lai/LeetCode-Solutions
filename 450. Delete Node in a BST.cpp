/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	int getNumChilds(TreeNode * root) { 
		int res = 0;
		if (root->left) res++;
		if (root->right) res++;
		
		return res;
	}
	
	void deleteNodeWithOneChild(TreeNode * curr, TreeNode * prev) {
		bool lft = (prev->left == curr) ? true : false;
		
		TreeNode * newChild = curr->left ? curr->left : curr->right;
		if (lft) {
			prev->left = newChild;
		} else {
			prev->right = newChild;
		}
	}
	
	void deleteNodeWithTwoChild(TreeNode * curr, TreeNode * prev) {
		bool lft = prev->left == curr ? true : false;
		TreeNode * root = curr;
		curr = root->left;
		if (getNumChilds(curr) == 0) {
			root->val = curr->val;
			root->left = nullptr;
			delete curr;
			return;
		}
		
		while (curr->right != nullptr) {
			prev = curr;    
			curr = curr->right;
		}
	
		TreeNode * tails = curr->left;
		if (curr == root->left) {
			root->left = tails;
			root->val = curr->val;
			delete curr;
		} else {
			prev->right = tails;
			root->val = curr->val;
			delete curr;
		}
	
	}
	
	void deleteNodeWithNoChild(TreeNode * curr, TreeNode * prev) {
		if (prev->left == curr) {
			prev->left = nullptr;
		} else {
			prev->right = nullptr;
		}
		
		delete curr;
	}
	
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr || (getNumChilds(root) == 0 && root->val == key)) return nullptr;
		
		TreeNode * prev = new TreeNode(-1); prev->right = root;
		TreeNode * curr = root;
		while (curr->val != key) {
			if (curr->val == key) break;
			
			prev = curr;
			if (key < curr->val) curr = curr->left;
			else curr = curr->right;
			
			if (curr == nullptr) return root;
		}
		
		int numChilds = getNumChilds(curr);
		if (numChilds == 0) {
			deleteNodeWithNoChild(curr, prev);
		} else if (numChilds == 2) {
			deleteNodeWithTwoChild(curr, prev);
		}
		else if (curr->right) {
			if (prev->left == curr) {
				prev->left = curr->right;    
			} else {
				prev->right = curr->right;
			}
			if (curr == root) {
				return curr->right;
			} else {
				delete curr;
			}
		}
		else if (curr->left) {
			if (prev->left == curr) {
				prev->left = curr->left;    
			} else {
				prev->right = curr->left;
			}
			if (curr == root) {
				return curr->left;    
			} else {
				delete curr;
			}
			
		}
		
		return root;
	}
};