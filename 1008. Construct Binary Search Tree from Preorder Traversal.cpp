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
public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		if (preorder.empty()) {
			return nullptr;
		}
		else if (preorder.size() == 1) {
			return new TreeNode(preorder[0]);
		}
		
		TreeNode * root = new TreeNode(preorder[0]);
		stack<TreeNode *> myStack;
		myStack.push(root);
		TreeNode * prevNode = root;
		
		for (int i = 1; i < preorder.size(); ++i) {
			TreeNode * cur = new TreeNode(preorder[i]);
			
			if (preorder[i] < myStack.top()->val) {
				myStack.top()->left = cur;
				myStack.push(cur);
			}
			else {
				TreeNode * prev;
				while (!myStack.empty() && myStack.top()->val < preorder[i]) {
					prev = myStack.top();
					myStack.pop();
				}
				
				prev->right = cur;
			}
			
			myStack.push(cur);
		}
	 
		return root;
	}
};